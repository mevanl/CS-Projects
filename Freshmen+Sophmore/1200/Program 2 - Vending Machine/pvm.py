'''
pvm.py
Mason Lauderdale 
Major: Computer Science 
10/21/2021
Purpose: Create a fully functional vending machine with the ability to calculate change.

'''
print("Welcome to the Python Vending Machine [PVM]\n-------------------------------------------")

# Create Varibles
Selection = 0 
userBill = []
cartCost = 0

# Loop so user can stop ordering or exit the program if they wish
while Selection == 0:
  print("\n\n     1. Coca-Cola - $1.50\n     2. Mtn Dew - $1.50\n     3. Pepsi - $1.50\n     4. M&Ms - $1.25\n     5. Water Bottle - $1.00\n")

  itemChoice = input("Enter the Number for the Item you would like or press 0 to quit: ")
  itemPrice = {'Coca-Cola':1.50, 'Mtn Dew':1.50, 'Pepsi':1.50, 'M&Ms':1.25, 'Water Bottle':1.00}

# Making sure user's choice is valid, and repeating until they stop
  if itemChoice not in ['1', '2', '3', '4', '5', '0']:
    print("Invalid Selection; Please input an integer 1 - 5 or 0 to quit/finish order.")
    Selection = 0
  
  if (itemChoice == '1'):
    userBill.append(itemPrice['Coca-Cola'])
    cartCost = cartCost + (itemPrice['Coca-Cola'])
    print("Added Coca-Cola to the Cart. Your total cart value is: ${:.2f}".format(cartCost))
    Selection = 0
  if (itemChoice == '2'):
    userBill.append(itemPrice['Mtn Dew'])
    cartCost = cartCost + (itemPrice['Mtn Dew'])
    print("Added Mtn Dew to the Cart. Your total cart value is: ${:.2f}".format(cartCost))
    Selection = 0
  if (itemChoice == '3'):
    userBill.append(itemPrice['Pepsi'])
    cartCost = cartCost + (itemPrice['Pepsi'])
    print("Added Pepsi to the Cart. Your total cart value is: ${:.2f}".format(cartCost))
    Selection = 0
  if (itemChoice == '4'):
    userBill.append(itemPrice['M&Ms'])
    cartCost = cartCost + (itemPrice['M&Ms'])
    print("Added M&Ms to the Cart. Your total cart value is: ${:.2f}".format(cartCost))
    Selection = 0
  if (itemChoice == '5'):
    userBill.append(itemPrice['Water Bottle'])
    cartCost = cartCost + (itemPrice['Water Bottle'])
    print("Added Water Bottle to the Cart. Your total cart value is: ${:.2f}".format(cartCost))
    Selection = 0 

# User can choose if they want to purchase something or exit the program
  if (itemChoice == '0'):
  	if (cartCost == 0):
  		userNoItem = input("You did not purchase anything. Press '1' if you would like to purchase an item.")
  		if (userNoItem == '1'):
  			Selection = 0
  		else:
  			quit()
  	if (cartCost != 0):
  		print("Thanks you for your purchase. Your total is: ${:.2f}".format(cartCost))
  		Selection = 1           

# New while loop to calculate money and ask user for money after item has been selected
while (Selection == 1):
  payedAmount = input("Enter Money into Machine to pay: $")
  payedAmount = float(payedAmount)

# Check if the user's money is enough to cover the purchase
  while (payedAmount < cartCost):
    additionalMoney = input("Not Enough Money, Please Enter More: $ ")
    additionalMoney = float(additionalMoney)
    payedAmount = (payedAmount + additionalMoney)
    additionalMoney = 0
  
  # If User's Money perfectly covers the cost, program finshed. 
  if (payedAmount == cartCost):
    Selection = 2
  
  # If user inputs more money that the cost of order, will calculate change
  if (payedAmount > cartCost):
    dollars = 0
    quarters = 0 
    dimes = 0
    nickels = 0
    pennies = 0

    if (payedAmount >= 1):
      dollars = (payedAmount)//(1)
      dollars = int(dollars)
    payedAmount = ((payedAmount) - (dollars))
    print("Dollars: ",dollars)

    if (payedAmount >= 0.25):
      quarters = (payedAmount)//(0.25)
      quarters = int(quarters)
    payedAmount = ((payedAmount) - (quarters * 0.25))
    print("Quarters: ", quarters)

    if (payedAmount >= 0.10):
      dimes = (payedAmount)//(0.10)
      dimes = int(dimes)
    payedAmount = ((payedAmount) - (dimes * 0.10))
    print("Dimes: ", dimes)

    if (payedAmount >= 0.05):
      nickels = (payedAmount)//(0.05)
      nickels = int(nickels)
    payedAmount = ((payedAmount) - (nickels * 0.05))
    print("Nickels: ", nickels)

    if (payedAmount >= 0.01):
      pennies = (payedAmount)//(0.01)
      pennies = int(pennies)
    payedAmount = ((payedAmount) - (pennies * 0.01))
    print("Pennies: ", pennies)
    Selection = 2

input("Transaction has concluded. Thank you for purchasing from the PVM!")