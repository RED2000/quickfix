package org.quickfix.field; 
import org.quickfix.CharField; 
import java.util.Date; 

public class OwnershipType extends CharField 
{ 
  public static final int FIELD = 517; 

  public OwnershipType() 
  { 
    super(517);
  } 
  public OwnershipType(char data) 
  { 
    super(517, data);
  } 
} 
