'''
Mason Lauderdale
CSC 1200-002 12/2/2021
Project 4
'''
import copy

def build_house():
  print("Please enter the house file: ")
  house_file = input()
  housefp = open(house_file, "r")
  myhouse = [] 
  line = housefp.readline()
  while line:
    myhouse.append(list(line))
    line = housefp.readline()
  return myhouse

def print_house(h,sr,sc):
  th = copy.deepcopy(h)
  th[sr][sc] = "@"
  for i in th:
    print(''.join(str(x) for x in i), end='')

def check_north(h, sr, sc):
	if h[sr-1][sc] != '*':
		print("Press W to go North.")
		return True
	else:
		return False
	
def check_south(h, sr, sc):
	if h[sr+1][sc] != '*':
		print("Press S to go South.")
		return True
	else:
		return False

def check_west(h, sr, sc):
	if h[sr][sc-1] != '*':
		print('Press A to go West.')
		return True
	else:
		return False

def check_east(h, sr, sc):
	if h[sr][sc+1] != '*':
		print('Press D to go East.')
		return True
	else:
		return False

def get_treasure(h, sr, sc):
	if h[sr][sc] == 't':
		h[sr][sc] = " "
		return True

def is_door(h, sr, sc):
	if h[sr][sc] == '5':
		return True
	elif h[sr][sc] == '6':
		return True
	elif h[sr][sc] == '7':
		return True
	elif h[sr][sc] == '8':
		return True
	elif h[sr][sc] == '9':
		return True
	else:
		False

def get_key(h, u, sr, sc):
	if h[sr][sc] == '0':
		u[0] = True
		h[sr][sc] = ' '
		return True
	elif h[sr][sc] == '1':
		u[1] = True
		h[sr][sc] = ' '
		return True
	elif h[sr][sc] == '2':
		u[2] = True
		h[sr][sc] = ' '
		return True
	elif h[sr][sc] == '3':
		u[3] = True
		h[sr][sc] = ' '
		return True
	elif h[sr][sc] == '4':
		u[4] = True
		h[sr][sc] = ' '
		return True
	else:
		return False

def can_unlock(h, u, sr, sc):
	if u[0] == True:
		if h[sr][sc] == '5':
			return True
	elif u[1] == True:
		if h[sr][sc] == '6':
			return True
	elif u[2] == True:
		if h[sr][sc] == '7':
			return True
	elif u[3] == True:
		if h[sr][sc] == '8':
			return True	
	elif u[4] == True:
		if h[sr][sc] == '9':
			return True
	else:
		return False

def main():
	# List of unlocked doors
	unlocked = [False, False, False, False, False]

	# HOUSE
	house = build_house()

	# Defining Player Start Location
	startrow = 2
	startcol = 3

	# Get Number of t's total in the house
	num_treasures = 0
	for items in house:
		for item in items:
			if item == 't':
				num_treasures += 1

	# Loop to see if user has collected all treasure
	tcount = 0 
	while tcount < num_treasures:

		# Show house and ask user to input available direction
		print_house(house, startrow, startcol)
		check_north(house, startrow, startcol)
		check_south(house, startrow, startcol)
		check_west(house, startrow, startcol)
		check_east(house, startrow, startcol)
		command = input("Enter a direction: ")
		print("\n\n")

		# Player Movement 
		if command == "w":
			trow = startrow-1
			tcol = startcol
		elif command == "d":
			trow = startrow
			tcol = startcol+1
		elif command == "s":
			trow = startrow+1
			tcol = startcol
		elif command == "a":
			trow = startrow
			tcol = startcol-1
		elif command == "q":
			break

		# So user's can't clip through walls
		if house[trow][tcol] == "*":
			print("You can not go that way!")
			continue 

		# Keys&Doors
		if is_door(house, trow, tcol) is True:
			if can_unlock(house, unlocked, trow, tcol) is False:
				trow = startrow 
				tcol = startcol 
				print("Sorry, the door is locked and you do not have the key")
			else:
				print("You unlocked the door.")
		else:
			if get_key(house, unlocked, trow, tcol) is True:
				print("You found a key!")

		# Allow user to pick up treasures
		if get_treasure(house, trow, tcol) is True:
			tcount += 1
			print(f'You have found a treasure! You currently have {tcount} treasure(s) and need {num_treasures} total.')

		# Change user coordinates when it loops back
		startrow = trow
		startcol = tcol

	# User Win Statement
	if tcount == num_treasures:
		print("Congratulations, You Win!")
main()
