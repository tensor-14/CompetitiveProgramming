def diff_(l1,l2):
    s = len(set(l1+l2))
    return s

for t in range(int(input())):
    n = int(input())
    l = input().split()
    dict_={}
    for i in l:
        p = i[1:]
        if p in dict_:
            dict_[p].append(i[0])
        else:
            dict_[p] = [i[0]]
    dict_1 = list(dict_.keys())
    s=0

    for i in range(len(dict_)):
        for j in range(i+1,len(dict_)):
            temp = diff_(dict_[dict_1[i]], dict_[dict_1[j]])
            s += (temp - len(dict_[dict_1[i]]))*(temp-len(dict_[dict_1[j]]))
    print(2*s)
