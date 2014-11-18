const maxn=2000001;

var
        tr:array[1..4*maxn] of longint;
        a:array[1..maxn] of longint;
        b:array[1..32] of longint;
        n,m,x,y,i,p:longint;

function max(a,b:longint):longint;
begin
        if a>b then exit(a) else exit(b);
end;

function build(nod,l,r:longint):longint;
begin
        if l=r then exit(tr[nod]);
        build:=0;
        build:=max(build(nod shl 1,l,(l+r) shr 1),build(nod shl 1+1,(l+r) shr 1+1,r));
        tr[nod]:=build;
end;

function count(nod,x,y,l,r:longint):longint;
var
        m,lch,rch:longint;
begin
        if (x=l)and(y=r) then exit(tr[nod]);
        m:=(l+r) shr 1;lch:=nod shl 1;rch:=nod shl 1+1;
        if m>=y then exit(count(lch,x,y,l,m));
        if x>m then exit(count(rch,x,y,m+1,r));
        exit(max(count(lch,x,m,l,m),count(rch,m+1,y,m+1,r)));
end;

begin
        readln(n);
        b[1]:=1;for i:=2 to 28 do b[i]:=b[i-1]*2;
        for i:=1 to n do if b[i]>n then break;
        p:=b[i];
        for i:=1 to n do read(tr[p+i-1]);
        build(1,1,p);
        readln(m);
        for i:=1 to m do
        begin
                readln(x,y);
                write(count(1,x,y,1,p),' ');
        end;
end.
