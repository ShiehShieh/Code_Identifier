const
    nlen = 40;

type
    num = array[1..nlen] of integer;

var
    time : longint;
    ta, tb : num;
    i, j, k : longint;
    s : string;
    d : num;
    nn, nk : integer;
    f : array[1..nlen, 1..nlen, 0..6] of num;
    t : longint;

function mul(a, b : num) : num;
    var
        i, j, t : integer;
        n : num;
    begin
        fillchar(n, sizeof(n), 0);
        for i := 1 to nlen do begin
            for j := 1 to nlen - i + 1 do begin
                n[i + j - 1] := n[i + j - 1] + a[i] * b[j];
            end;
        end;
        for i := 1 to nlen - 1 do begin
            n[i + 1] := n[i + 1] + n[i] div 10;
            n[i] := n[i] mod 10;
        end;
        exit(n);
    end;

function get(s : string) : num;
    var
        i : integer;
        len : integer;
    begin
        fillchar(get, sizeof(get), 0);
        len := length(s);
        for i := 1 to len do begin
            get[i] := ord(s[len - i + 1]) - ord('0');
        end;
    end;

procedure print(a : num);
    var
        i : integer;
    begin
        i := nlen;
        while a[i] = 0 do begin
            i := i - 1;
            if i = 0 then begin
                writeln(0);
                exit;
            end;
        end;
        write(a[i]);
        i := i - 1;
        while i <> 0 do begin
            write(a[i]);
            i := i - 1;
        end;
        writeln;
    end;

function max(a, b : num) : num;
    var
        i : integer;
    begin
        for i := nlen downto 1 do begin
            if a[i] = b[i] then begin
                continue;
            end;
            if a[i] > b[i] then begin
                exit(a);
            end;
            exit(b);
        end;
        exit(a);
    end;

procedure cutint;
    var
        i, j, k : integer;
    begin
        fillchar(f, sizeof(f), 0);
        for i := 1 to nn do begin
            for j := i to nn do begin
                for k := i to j do begin
                    f[nn - j + 1, nn - i + 1, 0, k - i + 1] := d[k];
                end;
            end;
        end;
    end;

begin
    readln(nn, nk);
    readln(s);
    d := get(s);
    cutint;
    for k := 1 to nk - 1 do begin
        for i := 1 to nn - k do begin
            for j := i + k to nn do begin
                for t := i to j - k do begin
                    f[i, j, k] := max(f[i, j, k], mul(f[i, t, 0], f[t + 1, j, k - 1]));
                end;
             //   write(k : 2, i : 2, j : 2, ' '); print(f[i, j, k]);
            end;
        end;
    end;
    for t := 1 to nn - nk do begin
        f[1, nn, nk] := max(f[1, nn, nk], mul(f[1, t, 0], f[t + 1, nn, nk - 1]))
    end;
    print(f[1, nn, nk]);
end.

