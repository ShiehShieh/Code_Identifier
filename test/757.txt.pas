type
   node = record
       data : dword;
       s : string;
   end;

var
    i, j, k : longint;
    d : array[1..30] of dword;
    f : array[1..30, 1..30] of node;
    n : longint;
    s : node;

function tostr(n : dword) : string;
    var
        k : integer;
    begin
        str(n, tostr);
    end;

function max(a, b : node) : node;
    begin
        if a.data > b.data then begin
            exit(a);
        end;
        exit(b);
    end;

function add(l, r : integer) : node;
    var
        i : integer;
        a, b : node;
        s : node;
        maxs : string;
        maxi : integer;
    begin
        if l > r then begin
            s.data := 1;
            s.s := '';
            exit(s);
        end;
        if f[l, r].data <> 0 then begin
            exit(f[l, r]);
        end;
        if l = r then begin
            s.data := d[l];
            s.s := tostr(l);
            exit(s);
        end;
        s.data := 0;
        for i := l to r do begin
            a := add(l, i - 1);
            b := add(i + 1, r);
            if a.data * b.data + d[i] > s.data then begin
                s.data := a.data * b.data + d[i];
                if a.s = '' then begin
                    s.s := tostr(i) + ' ' + b.s;
                    continue;
                end;
                if b.s = '' then begin
                    s.s := tostr(i) + ' ' + b.s;
                    continue;
                end;
                s.s := tostr(i) + ' ' + a.s + ' ' + b.s;
            end;
        end;
        f[l, r] := s;
        exit(s)
    end;


begin
    readln(n);
    for i := 1 to n do begin
        read(d[i]);
        for j := 1 to n do begin
            f[i, j].data := 0;
            f[i, j].s := '';
        end;
    end;
    readln;
    s := add(1, n);
    writeln(s.data);
    writeln(s.s);
end.
