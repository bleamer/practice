def kthsmallest( A, k):
    # temp = [None] * (k+1)
    temp = []
    A_list = []
    for i in range(len(A)):
        A_list.append( (A[i]) )
    # temp = A_list[0:k+1]
    A_list.sort()
    # print
    print(temp)
    print (A_list)
    for i in xrange(0,len(A_list)):
        # temp.append(A_list[i])
        # if A_list[i] not in temp:
        temp.append(A_list[i])
        temp.sort()
        print(temp,A_list[i])
        if len(temp) > k:
            del(temp[-1])
    print(temp)
    # print (temp[-1])
    return temp[-1]

def main():
    print(kthsmallest((8, 16, 80, 55, 32, 8, 38, 40, 65, 18, 15, 45, 50, 38, 54, 52, 23, 74, 81, 42, 28, 16, 66, 35, 91, 36, 44, 9, 85, 58, 59, 49, 75, 20, 87, 60, 17, 11, 39, 62, 20, 17, 46, 26, 81, 92),9))

if __name__ == '__main__':
    main()
