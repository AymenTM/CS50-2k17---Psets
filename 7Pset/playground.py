

with open('playground.py', 'rb') as rf:
	with open('copy.txt', 'wb') as wf:

		chunk_size = 512
		rf_chunk = rf.read(chunk_size)

		while len(rf_chunk) > 0:
			wf.write(rf_chunk)
			rf_chunk = rf.read(chunk_size)
