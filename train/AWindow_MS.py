def bfs():
	ins = open("", 'r')
	ous = open("", 'w')
	i = 0
	query=""
	strs=""
	for line in ins:
		if i is 0:
			query = line[:-1]
		if i>0:
			if line[-1] is "\n":
				line = line[:-1]	
			strs += line
		i += 1

	first = 0
	times = 0
	complete = 0
	l = len(strs)
	res=""
	words = strs.split(" ")
	for word in words:
		if word.lower() == query:
			print word
			complete += 1
			times += 1
		elif query in word.lower() and word.lower().index(query) == 0:
			print word
			if times == 0:
				res = word

			
			times += 1
			
	print complete, times, res
	ous.write(str(complete)+";"+str(times)+";"+res)	

		
if __name__ == "__main__":
	bfs()

		
