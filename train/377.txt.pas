{
ID:shadow_3
PROG:p1514
LANG:PASCAL
}

const
	tsize=500000;

type
	lttype=record
		lc,rc,l,r,max:longint;
	end;

var
	i,n,a,b,t,tree,rp:longint;
	lt:array[0..tsize]of lttype;


function create(l,r:longint):longint;
var
	t:longint;
begin
	inc(rp);
	t:=rp;
	create:=t;
	lt[t].l:=l;
	lt[t].r:=r;
	lt[t].max:=-maxlongint;
	if l=r then exit;
	lt[t].lc:=create(l,(l+r) div 2);
	lt[t].rc:=create((l+r) div 2+1,r);
end;

procedure add(t,i,k:longint);
begin
	if lt[t].l=lt[t].r then
	begin
		lt[t].max:=k;
		exit;
	end;
	if i<=(lt[t].l+lt[t].r) div 2
		then add(lt[t].lc,i,k)
		else add(lt[t].rc,i,k);
	if lt[lt[t].lc].max>lt[lt[t].rc].max
		then lt[t].max:=lt[lt[t].lc].max
		else lt[t].max:=lt[lt[t].rc].max;
end;

function ltmax(t,a,b:longint):longint;
var
	left,right:longint;
begin
	if (t=0) or (a>lt[t].r) or (b<lt[t].l) then exit(-maxlongint);
	if (a<=lt[t].l) and (b>=lt[t].r) then exit(lt[t].max);
	left:=ltmax(lt[t].lc,a,b);
	right:=ltmax(lt[t].rc,a,b);
	if left>right then exit(left) else exit(right);
end;

procedure print;
var
        i:longint;
begin
        exit;
        for i:=1 to rp do
                writeln('L=',lt[i].l,' R=',lt[i].r,' MAX=',lt[i].max);
        writeln;
end;

begin



	readln(n);
	lt[0].max:=-maxlongint;
	tree:=create(1,n);
        print;
	for i:=1 to n do
	begin
		read(t);
		add(tree,i,t);
                print;
	end;

	readln(n);
	for i:=1 to n do
	begin
		read(a,b);
                write(ltmax(tree,a,b));
                if i<>n then write(' ') else writeln;
	end;



end.

