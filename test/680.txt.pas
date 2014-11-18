const
    maxn = 1000;
var
    i, j, k : integer;
    d : array[1..maxn * 2] of dword;
    f : array[1..maxn * 2, 1..maxn * 2] of dword;
    n : integer;
    s : dword;

function max(a, b : dword) : dword;
    begin
        if a > b then begin
            exit(a);
        end;
        exit(b);
    end;

begin
    fillchar(f, sizeof(f), 0);
    readln(n);
    for i := 1 to n do begin
        read(d[i]);
        d[i + n] := d[i];
    end;
    for i := 1 to n * 2 - 1 do begin
        f[i, i] := d[i];
    end;
    for k := 3 to n + 1 do begin
        for i := 1 to n * 2 - k + 1 do begin
            for j := i + 1 to i + k - 2 do begin
                f[i, i + k - 1] := max(f[i, i + k - 1], f[i, j] + f[j, i + k - 1] + d[i] * d[j] * d[i + k - 1]);
            end;
  //          writeln(i, ' ', i + k - 1,'''', f[i, i + k - 1]);
        end;
    end;
    s := 0;
    for i := 1 to n do begin
        s := max(s, f[i, i + n]);
    end;
    writeln(s);
end.

