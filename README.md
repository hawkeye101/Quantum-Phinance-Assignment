Quantum Phinance Assignment

NAME: ARVIND GANESH

This is the solution to the assignment from Quantum Phinance Pvt Ltd.

1. Main file is 'loan_charges.cpp', a C++ program which computes charges for each condition, and total charges, for each test case.

2. Data is input at 'input.txt' in the following format. All dates are in format like 1-Jun-20:

  No. of test cases (TC)
  
  Amount TC1
  
  Duration in years TC1
  
  Start date TC1
  
  No. of conditions TC1
  
  Start_date condition 1 TC1
  
  End_date condition 1 TC1
  
  Interest rate condition 1 TC1
  
  Start_date condition 2 TC1
  
  End_date condition 2 TC1
  
  Interest rate condition 2 TC1
  
  .
  
  .
  
  .
  
  Start_date condition n TC1
  
  End_date condition n TC1
  
  Interest rate condition n TC1
  
  Max_rate for particular period TC1
  
  Amount TC2
  
  Duration in years TC2
  
  Start date TC2
  
  No. of conditions TC2
  
  Start_date condition 1 TC2
  
  End_date condition 1 TC2
  
  Interest rate condition 1 TC2
  
  Start_date condition 2 TC2
  
  End_date condition 2 TC2
  
  Interest rate condition 2 TC2
  
  .
  
  .
  
  .
  
  Start_date condition n TC2
  
  End_date condition n TC2
  
  Interest rate condition n TC2
  
  Max_rate for particular period TC2
  
  .
  
  .
  
  .


2. Output file is 'output.txt' in the following format:

  Condition 1 charge TC1
  
  Condition 2 charge TC1
  
  .
  
  .
  
  .
  
  Condition n charge TC1
  
  Total charge TC1
  
  Condition 1 charge TC2
  
  Condition 2 charge TC2
  
  .
  
  .
  
  .
  
  Condition n charge TC2
  
  Total charge TC2
  
  .
  
  .
  
  .
  
  
3. Currently program has run for two test cases. Check 'input.txt'.
  
  Test Case I
    
    Loan amount = 100, duration = 1 year, start_date = 1-Jan-20, no_of_conditions = 2
    
    condition 1
      
      start_date = 10-Jan-20
      
      end_date = 20-Jan-20
      
      interest rate = 2%
    
    condition 2
      
      start_date = 15-Jan-20
      
      end_date = 25-Jan-20
      
      interest rate = 3%
    
    max_interest_rate = 4%
  
  Test Case II
    
    Loan amount = 300, duration = 2 years, start_date = 10-Mar-16, no_of_conditions = 3
    
    condition 1
      
      start_date = 15-Mar-16
      
      end_date = 12-Jun-16
      
      interest rate = 5%
    
    condition 2
      
      start_date = 15-May-16
      
      end_date = 9-Apr-17
      
      interest rate = 6%
    
    condition 3
      
      start_date = 10-Dec-17
      
      end_date = 12-Feb-18
      
      interest rate = 5%
    
    max_interest_rate = 10%
    
4. Output formula is amount * time_duration * rate (in %) / 100 / 365 for a particular period. If overlaps exist, the sum of interest rates
is checked against max_interest_rate and decided accordingly.


5. For the above test case, output from 'output.txt' is as follows:
  
  Test Case I
    
    Condition 1 charge = 0.059
    
    Condition 2 charge = 0.088
    
    Total charges = 0.147
  
  Test Case II
    
    Condition 1 charge = 3.631
    
    Condition 2 charge = 16.144
    
    Condition 3 charge = 2.630
    
    Total charges = 22.405

