program p1112;
var n,m,i,j,k,x,y,a,b,c,d:longint;
    s:string;
    f,h:array[0..20000] of longint;
function find(x:longint):longint;
begin
    if f[x]=x then exit(x);
    if f[x]=f[f[x]] then exit(f[x]);
    f[x]:=find(f[x]);
    exit(f[x]);
end;
function hash(x:longint):longint;
var y:longint;
begin
    y:=x mod 6000;
    while (h[y]<>-1)and(h[y]<>x) do
    y:=(y+1) mod 6000;
    h[y]:=x;
    exit(y);
end;
Begin
    readln(n);
    readln(m);
    for i:=0 to 20000 do begin f[i]:=i;h[i]:=-1; end;
    for i:=1 to m do
    begin
        readln(x,y,s);
        x:=hash(x-1);
        y:=hash(y);
        a:=find(x);
        b:=find(y);
        c:=find(x+10000);
        d:=find(y+10000);
        if s[2]='e' then
        begin
             if a=d then
             begin
                 writeln(i-1);
                 halt;
             end;
             if a<>b then f[a]:=b;
             if c<>d then f[c]:=d;
        end
        else
        begin
             if a=b then
             begin
                 writeln(i-1);
                 halt;
             end;
             if c<>b then f[c]:=b;
             if a<>d then f[a]:=d;
        end;
    end;
    writeln(m);
End.
