var
    i, j, k : integer;
    d : array[1..100, 1..100] of boolean;
    m, n : integer;
    ch : char;
    max : integer;
    ss : integer;

function search(x, y : integer) : integer;
    var
        i, j, s : integer;
    begin
        s := 0;
        for i := x to x + n - 1 do begin
            for j := y to y + n - 1 do begin
                if d[i, j] then begin
                    s := s + 1;
                end;
            end;
        end;
        exit(s);
    end;

begin
    readln(m, n);
    if n > m then begin
        n := m;
    end;
    for i := 1 to m do begin
        for j := 1 to m do begin
            read(ch);
            if ch = '.' then begin
                d[i, j] := false;
            end
            else begin
                d[i, j] := true;
            end;
        end;
        readln;
    end;
    max := 0;

    for i := 1 to m - n + 1 do begin
        for j := 1 to m - n + 1 do begin
            ss := search(i, j);
            if ss > max then begin
                max := ss;
            end;
        end;
    end;
    writeln(max);
end.
