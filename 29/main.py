def main():

    l = []

    for a in range(2, 101):
        for b in range(2, 101):
            v = a**b
            if v not in l:
                l.append(v)
    
    print(len(l))

if __name__ == '__main__':
    main()