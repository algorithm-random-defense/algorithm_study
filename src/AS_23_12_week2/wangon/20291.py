n = int(input())
ret = {}

for i in range(n):
    instr = str(input())
    sep = instr.find('.')
    ext = instr[sep+1:len(instr)]
    if ext in ret:
        ret[ext] += 1
    else:
        ret[ext] = 1

for key, item in sorted(ret.items()):
    print(f"{key} {item}")
