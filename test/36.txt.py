def main():
    V, M = raw_input().split(" ")
    N = raw_input()
    V = int(V)
    M = int(M)
    N = int(N)
    f = []
    for i in range(401):
        f.append([])
        for j in range(401):
            f[i].append(0)

    for i in range(N):
        v, m, cal = raw_input().split(" ")
        v = int(v)
        m = int(m)
        cal = int(cal)
        j = V
        while j >= v:
            k = M
            while k >= m:
                f[j][k] = max(f[j][k], f[j-v][k-m] + cal)
                k -= 1
            j -= 1
    print f[V][M]
    return

main()
