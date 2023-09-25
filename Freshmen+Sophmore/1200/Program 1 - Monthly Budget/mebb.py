'''
mebb.py
Mason Lauderdale 
Major: Computer Science 
9/14/2021
Purpose: Make a program that calcuates the user's monthly budget based off of expenses they input
'''

# Making Loop incase user wants to try again
program = ("running")
program = str(program)
while program == ("running"):
	# Start by introducing what the program is and asking for the user's name
	print("\n\nWelcome to the Monthly Expenses Budget Builder [MEBB]\n")

	userName = input("What is your name? ")
	userName = str(userName)

	input("\nHello " + userName + "! Please press Enter and fill out all fields.\n")
	print("\n     Budget Builder\n     ------ -------")

	# All Budget related inputs 
	print("\nEnter the monthly value for each field:\n")
	monthlyIncome = input("Income: $")
	monthlyIncome = float(monthlyIncome)

	home = input("House Payment or Rent Bill: $")
	home = float(home)

	electric = input("Electric Bill: $")
	electric = float(electric)

	water = input("Water Bill: $")
	water = float(water)

	internet = input("Internet Bill: $")
	internet = float(internet)

	phone = input("Phone Bill: $")
	phone = float(phone)

	car = input("Car Payment: $")
	car = float(car)

	gas = input("Gas Bill: $")
	gas = float(gas)

	insurance = input("Insurance Bills: $")
	insurance = float(insurance)

	food = input("Food Bill: $")
	food = float(food)

	savings = input("Savings: $")
	savings = float(savings)

	otherExpenses = input("Other Expenses: $")
	otherExpenses = float(otherExpenses)


	# Calculations 
	monthlyCost = float(home + electric + water + internet + car + phone + insurance + gas + food + savings + otherExpenses)
	monthlyBalance = (float(monthlyIncome) - float(monthlyCost))


	# Percent for Budget Suggestions if Negative 
		# Housing[30%], Utilites[15%], Insurance[10%], Transportation[15%], Food[10%], Savings [10%], Other[10%].
	homePercent = float((home)/(monthlyIncome) * 100)
	homePercent = int(homePercent)

	electricPercent = float((electric)/(monthlyIncome) * 100)
	electricPercent = int(electricPercent)

	waterPercent = float((water)/(monthlyIncome) * 100)
	waterPercent = int(waterPercent)

	internetPercent = float((internet)/(monthlyIncome) * 100)
	internetPercent = int(internetPercent)

	phonePercent = float((phone)/(monthlyIncome) * 100)
	phonePercent = int(phonePercent)

	utilityPercent = float(electricPercent + waterPercent + internetPercent + phonePercent)
	utilityPercent = int(utilityPercent)

	insurancePercent = float((insurance)/(monthlyIncome) * 100)
	insurancePercent = int(insurancePercent)

	carPercent = float((car)/(monthlyIncome) * 100)
	carPercent = int(carPercent)

	gasPercent = float((gas)/(monthlyIncome) * 100)
	gasPercent = int(gasPercent)

	transportationPercent = float(carPercent + gasPercent)
	transportationPercent = int(transportationPercent)

	foodPercent = float((food)/(monthlyIncome) * 100)
	foodPercent = int(foodPercent)

	savingsPercent = float((savings)/(monthlyIncome) * 100)
	savingsPercent = int(savingsPercent)

	otherPercent = float((otherExpenses)/(monthlyIncome) * 100)
	otherPercent = int(otherPercent)

	# Output 
	print("\n     Results\n     -------\n")
	if monthlyBalance >= 0:
		monthlyBalance = str(monthlyBalance)
		print("Your cost of living is within your income! Your balance is $" + monthlyBalance)
	else:
		monthlyBalance = str(monthlyBalance)
		print("Your monthly cost is greater than your monthly income! Your balance is: $" + monthlyBalance)
		print("\nSuggestions to lower cost: ")		
		if homePercent > 30:
			homePercent = str(homePercent)
			print("Try spending less on rent/house payment, it takes up " + homePercent +  "%" + " of your total monthly budget. You could move into a less expensive place or talk to your home's owener.")
		
		elif insurancePercent > 10:
			insurancePercent = str(insurancePercent)
			print("Try spending less on your insurance, it takes up " + insurancePercent + "%" + " of your total monthly budget. Try to get a cheaper insurance plan or change insurance companies.")

		elif transportationPercent > 15:
			transportationPercent = str(transportationPercent)
			print("Try to spend less on transportation, it takes up " + transportationPercent + "%" + " of your total monthly budget. Try to save on gas or get a cheaper vehicle.")
		
		elif utilityPercent > 15:
			utilityPercent = str(utilityPercent)
			print("Try spending less on your utilities (Electric, Water, Internet, Phone), it takes up " + utilityPercent + "%" + " of your total monthly budget. Try to use less electricity, use less water, or get a cheaper internet and phone plan.")
		
		elif foodPercent > 10:
			foodPercent = str(foodPercent)
			print("Try to spend less on food, it takes up " + foodPercent + "%" + " of your total monthly budget. Try to eat out less, and make your own meals.")
		
		elif savingsPercent > 10: 
			savingsPercent = str(savingsPercent)
			print("Try to put less of your money into savings, it takes up " + savingsPercent + "%" + " of your total monthly budget. Try to save a less and put it towards other expenses.")
		
		else:
			otherPercent > 10
			otherPercent = str(otherPercent)
			print("Try to spend less on miscellaneous expenses, it takes up " + otherPercent + "%" + " of your total monthly budget. Try to spend less on personal or recreational items.")
				
	reset = input("\n\nMEBB has finished. Enter to Exit or 'reset' to restart the program. ")
	reset = str(reset)
	if reset != ("reset"):
		break