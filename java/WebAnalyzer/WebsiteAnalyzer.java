import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;
import java.util.SortedMap;
import java.util.SortedSet;
import java.util.TreeMap;
import java.util.TreeSet;

public class WebsiteAnalyzer {
	
	// Maintain a table to index different urls
	HashMap<String, PageData> PageIndex;
	
	// Function to be called when a page is accessed
	public void reportPageAccess(String pageUrl) 
	{
		if (pageUrl == null) // Sanity check
		{
			// Do some error handling here, 
			// currently just return from here
			System.out.println("Invalid string");
			return;
		}
		
		// Search if the current URL exists in the current database
		if ( PageIndex.containsKey(pageUrl) )
		{
			// If it exists increase the Page hit count for this page
			PageIndex.get(pageUrl).hitCount += 1; 
		}
		else // Page does not exist in the analyzer
		{
			// Create an entry and set the hit count to 1
			PageIndex.put(pageUrl, new PageData());
		}
	}
	 	// Function to return 'N' top pages with maximum hit count
	public List<String> getTopNPages(int n) 
	{
			// Get the entry set for iterating
			Set pageSet = PageIndex.entrySet();

			// Place holder to have page data sorted based on number of hits 
			// of all Pages in PageIndex
			SortedMap<Integer, PageData> topPages = new TreeMap();
			
			// Iterate over all pages
			Iterator<PageData> itr = pageSet.iterator();
			while(itr.hasNext())
			{
				PageData tmp = (PageData)itr.next();
				// Insert each page into a sorted map based on hitcount
				topPages.put(tmp.hitCount, tmp);
			}
				
			int count = n;
			// Get the entry set for iterating over top pages
			Set topSet = topPages.entrySet();
			Iterator it = topSet.iterator();
			
			// List containing URLs to be returned.
			List<String> returnedPages = new LinkedList<String>();
			
			// While the sorted set is not empty and we
			// have not added requested number of pages to 
			// the list to be returned
			while(it.hasNext() && count > 0)
			{
				PageData tmp = (PageData)it.next();
				// Append the url to the list
				returnedPages.add(tmp.url);
				// Decrement the running count
				--count;
			}
							
			return returnedPages;
		}
		 

		public WebsiteAnalyzer()
		{
			PageIndex = new HashMap();
		}
	}
