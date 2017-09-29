import datetime

# normal way
n = int(input('Enter the number: '))
# print('Factors:')
count = 0
a = datetime.datetime.now()
for i in range(1, n+1):
	if n % i == 0:
		# print(i)
		count += 1
b = datetime.datetime.now()
c = b - a
print('\nNormal Way:\n')
print('No. of Factors: ' + str(count))
print('Time Taken: ' + str(c.microseconds))

# optimal way to find all the factors
i = 1
l = n
# print('Factors:')
count = 0
a = datetime.datetime.now()
while i < l:
	if n % i == 0:
		# print(i)
		l = n / i
		# print(int(l))
		count += 2
	i += 1
b = datetime.datetime.now()
c = b - a
print('\nOptimal Way:\n')
print('No. of Factors: ' + str(count))
print('Time Taken: ' + str(c.microseconds))
