s = input()
res = 0
so = []
dau = []

for i in range(len(s)):
    if s[i] == "+" or s[i] == "-":
        dau.append(s[i])

i = 0
number = ["1", "2", "3", "4", "5", "6", "7", "8", "9"]
while i < (len(s)):
    temp = ""
    while i < (len(s)) and s[i] in number:
        temp += s[i]
        i += 1

    if temp != "":
        so.append(int(temp))
    i += 1

for i in range(len(so)):
    if dau[i] == "+":
        res += so[i]
    else:
        res -= so[i]
print(res)
