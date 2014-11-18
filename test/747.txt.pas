const
    maxn = 50;
var
    g : array[1..2000, 1..2000] of char;
    m, n : integer;
    x, y : integer;
    d : array[1..maxn, 1..maxn] of integer;
    w, h : integer;
    i, j, k : integer;

function max(a, b : integer) : integer;
    begin
        if a > b then begin
            exit(a);
        end;
        exit(b);
    end;

procedure draw(x, y : integer);
    begin
        x := x - 1;
        y := y - 1;

        g[x + 1, y + 3] := '+';
        g[x + 1, y + 7] := '+';
        g[x + 3, y + 1] := '+';
        g[x + 3, y + 5] := '+';
        g[x + 4, y + 7] := '+';
        g[x + 6, y + 1] := '+';
        g[x + 6, y + 5] := '+';

        g[x + 2, y + 2] := '/';
        g[x + 2, y + 6] := '/';
        g[x + 5, y + 6] := '/';

        g[x + 2, y + 3] := ' ';
        g[x + 2, y + 4] := ' ';
        g[x + 2, y + 5] := ' ';

        g[x + 3, y + 6] := ' ';
        g[x + 4, y + 6] := ' ';

        g[x + 4, y + 2] := ' ';
        g[x + 4, y + 3] := ' ';
        g[x + 4, y + 4] := ' ';
        g[x + 5, y + 2] := ' ';
        g[x + 5, y + 3] := ' ';
        g[x + 5, y + 4] := ' ';

        g[x + 1, y + 4] := '-';
        g[x + 1, y + 5] := '-';
        g[x + 1, y + 6] := '-';

        g[x + 3, y + 2] := '-';
        g[x + 3, y + 3] := '-';
        g[x + 3, y + 4] := '-';

        g[x + 6, y + 2] := '-';
        g[x + 6, y + 3] := '-';
        g[x + 6, y + 4] := '-';

        g[x + 4, y + 1] := '|';
        g[x + 5, y + 1] := '|';

        g[x + 4, y + 5] := '|';
        g[x + 5, y + 5] := '|';

        g[x + 2, y + 7] := '|';
        g[x + 3, y + 7] := '|';

    end;

procedure print;
    var
        i, j : integer;
    begin
        for i := 1 to h do begin
            for j := 1 to w do begin
                write(g[i, j]);
            end;
            writeln;
        end;
    end;

begin
    fillchar(g, sizeof(g), '.');
    readln(m, n);
    w := m * 2 + n * 4 + 1;
    h := 0;
    for i := 1 to m do begin
        for j := 1 to n do begin
            read(d[i, j]);
            h := max(h, d[i, j] * 3 + 3 + (m - i) * 2);
        end;
        readln;
    end;
    for i := 1 to m do begin
        for j := 1 to n do begin
            for k := 1 to d[i, j] do begin
                x := h + 1 - (2 * (m - i) + 3 + 3 * k);
                y := 2 * (m - i) + 4 * j - 3;
                draw(x, y);
            end;
        end;
    end;
    print;
end.
