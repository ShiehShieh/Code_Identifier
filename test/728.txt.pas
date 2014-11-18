var
    i, n : integer;
    g : array[1..9, 1..9] of integer;

procedure inp;
    var
        i, j : integer;
    begin
        for i := 1 to 9 do begin
            for j := 1 to 9 do begin
                read(g[i, j]);
            end;
            readln;
        end;
        readln;
    end;

function test(x, y : integer) : boolean;
    var
        i, j : integer;
        f : array[1..9] of boolean;
    begin
        fillchar(f, sizeof(f), false);
        for i := 1 to 3 do begin
            for j := 1 to 3 do begin
                if f[g[x + i - 1, y + j - 1]] then begin
                    exit(false);
                end;
                f[g[x + i - 1, y + j - 1]] := true;
            end;
        end;
        exit(true);
    end;

procedure process;
    var
        i, j : integer;
        f : array[1..9] of boolean;
    begin
        for i := 1 to 3 do begin
            for j := 1 to 3 do begin
                if not test(i * 3 - 2, j * 3 - 2) then begin
                    writeln('Wrong');
                    exit;
                end;
            end;
        end;

        for i := 1 to 9 do begin
            fillchar(f, sizeof(f), false);
            for j := 1 to 9 do begin
                if f[g[i, j]] then begin
                    writeln('Wrong');
                    exit;
                end;
                f[g[i, j]] := true;
            end;
        end;
        for j := 1 to 9 do begin
            fillchar(f, sizeof(f), false);
            for i := 1 to 9 do begin
                if f[g[i, j]] then begin
                    writeln('Wrong');
                    exit;
                end;
                f[g[i, j]] := true;
            end;
        end;

        writeln('Right');
    end;

begin
    readln(n);
    for i := 1 to n do begin
        inp;
        process;
    end;
end.

