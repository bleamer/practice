package org.aopdemo.aspect;

import org.aopdemo.model.Circle;
import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;
import org.aspectj.lang.annotation.Pointcut;


//@Aspect
public class LoggingAspect {
	//@Before("allGetters()")
	public void LoggingAdvice(){
		System.out.println("Advice run. Get method called");
	}

	//@Before("allGetters()")
	public void LoggingSecondAdvice(){
		System.out.println("Advice run. Get method called");
	}

	//@Before("allCircleMethods()")
	public void CircleMethods(JoinPoint joinPoint){
		Circle circle = (Circle) joinPoint.getTarget(); 
		System.out.println("Calling circle methods");
	}
	
	//@Before("args(name)")
	public void stringArgMethod(String name){
		System.out.println("STring arguments being called : "+ name);
	}
	
	// Point Cut is used to generate common annotation expression
	@Pointcut("execution(* get*())")
	public void allGetters(){};
	
	
	@Pointcut("within(org.aopdemo.model.Circle)")
	public void allCircleMethods(){}
}
