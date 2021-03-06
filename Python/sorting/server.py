#!/usr/bin/env python
# -*- coding: utf-8 -*-
import os, signal
from subprocess import Popen, PIPE
# string.Template requires Python 2.4+
from string import Template

import subprocess

import cherrypy

import algoEntry   


# Thanks to DanMcDougall and joshthecoder for the reference code
#__author__ = 'Dan McDougall <YouKnowWho@YouKnowWhat.com>'
# Thanks to joshthecoder for the pid-in-session bit

# Trying to cut down on long lines...
jquery_url = 'http://ajax.googleapis.com/ajax/libs/jquery/1.3.2/jquery.min.js'
jquery_ui_url = 'http://ajax.googleapis.com/ajax/libs/jqueryui/1.7.2/jquery-ui.min.js'
jquery_ui_css_url = \
'http://ajax.googleapis.com/ajax/libs/jqueryui/1.7.2/themes/black-tie/jquery-ui.css'

class Comet(object):
    """An example of using CherryPy for Comet-style asynchronous communication"""
    @cherrypy.expose
    def index(self):
        """Return a basic HTML page with a Execute Algorithms form, a Cancel form, and an iframe"""
        # Note: Dollar signs in string.Template are escaped by using two ($$)
        html = """\
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="en">
  <head>
    <link rel="stylesheet" type="text/css" href="${jquery_ui_css_url}" media="screen" />
    <script type="text/javascript" src="${jquery_url}"></script>
    <script type="text/javascript" src="${jquery_ui_url}"></script>
    <style>
    .fg-button {
    outline: 0;
    clear: left;
    margin:0 4px 0 0;
    padding: .1em .5em .1em .5em;
    text-decoration:none !important;
    cursor:pointer;
    position: relative;
    text-align: center;
    zoom: 1;
    }
    .fg-button .ui-icon {
    position: absolute;
    top: 50%;
    margin-top: -8px;
    left: 50%;
    margin-left: -8px;
    padding: .1em .5em .1em .5em;
    }
    a.fg-button { float:left;  }
    .terminal {
    position: relative;
    top: 0;
    left: 0;
    display: block;
    font-family: monospace;
    white-space: pre;
    width: 100em; height: 25em;
    border: ridge;
    }
    </style>
  </head>
  <body>
  <script type="text/javascript">
    $$(function(){
        $$('#result').hide();
        $$('#kill_AlgoExec').click(function() {
            $$.ajax({
                url: "/kill_proc",
                cache: false,
                success: function(html){
                    window.frames[0].stop();
                    $$("#result").html(html);
                    $$("#result").show('slow');
                }
            });
            return false;
        });
    });
    </script>
  <h3>Algorithms Comparison</h3>
  <form id="execForm" target="console_iframe" method="post" action="/execFormFunc">
  <!--input type="text" id="host" name="host" size="18" /-->
  <button id="Execute Algorithms" class="fg-button ui-state-default ui-corner-all" type="submit">
  Execute Algorithms
  </button>
  </form>
  <form id="kill_form" method="post" action="/kill_proc">
  <button id="kill_AlgoExec" class="fg-button ui-state-default ui-corner-all"
  title="Click to stop executing Algorithm Comparison (sends SIGINT)" type="submit">
  Cancel
  </button>
  </form>
  <div id="result" class="ui-state-highlight">
  <span class="ui-icon ui-icon-check ui-icon-left" style="margin-right: .3em;">
  </span>
  </div>
  <iframe name="console_iframe" class="terminal" />  
  </body>
</html>
"""
        t = Template(html)
        page = t.substitute(
            jquery_ui_css_url=jquery_ui_css_url,
            jquery_url=jquery_url,
            jquery_ui_url=jquery_ui_url)
        return page

    @cherrypy.expose
    def execFormFunc(self, **kw):
        """Execute, algoEntry and stream the output"""
        command = "python algoEntry.py 1"
        # This javascript just scrolls the iframe to the bottom
        scroll_to_bottom = '<script type="text/javascript">window.scrollBy(0,10000);</script>'
        process = Popen(command, shell=True, stdout=PIPE, stderr=PIPE,
                        close_fds=True, preexec_fn=os.setsid)
        # Save the pid in the user's session (a thread-safe place)
        cherrypy.session['pid'] = process.pid
        cherrypy.session.save()
        def run_command():
            # The yields here are the key to keeping things streaming
            yield '<style>body {font-family: monospace;}</style>'
            while not process.poll(): # While the process is still running...
                out = process.stdout.read(1) # Read it's output a character at a time
                # out = process.stdout.readline() # Read it's output a character at a time
                if out == '\n': # Since we're not using text/plain we need line break tags
                    out = "\n<br />%s" % scroll_to_bottom # include the iframe scroll fix
                yield out # Stream it to the browser
            # Now write out anything left in the buffer...
            out = ""
            for char in process.stdout.read():
                if char == "\n":
                    out += "\n<br />%s" % scroll_to_bottom
                else:
                    out += char
            yield out
        return run_command()
        
    # Enable streaming for the ping method.  Without this it won't work.
    execFormFunc._cp_config = {'response.stream': True}

    @cherrypy.expose
    def kill_proc(self, **kw):
        """Kill the process associated with the pid in our session."""
        pid = cherrypy.session.get('pid')
        if not pid:
            return "No active process to kill"
        # Without SIGINT we don't get the final summary from the ping command
        # ...it emulates control-C (SIGKILL or SIGTERM would just end the process with no summary)
        os.killpg(pid, signal.SIGINT)
        return "<strong>Success:</strong> The Algorithm comparison was cancelled."

cherrypy.config.update({
    'log.screen':True,
    'tools.sessions.on': True,
    'checker.on':False
})
cherrypy.tree.mount(Comet(), config=None)
cherrypy.engine.start()
cherrypy.engine.block()