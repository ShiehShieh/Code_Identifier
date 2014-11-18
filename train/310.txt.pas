{
ID:shadow_3
PROG:p1412
LANG:PASCAL
}
{$inline on}

const
	maxn=200;
	maxv=5000;
	maxns=50;

var
	i,n,j,k,max,vv,ns,ans:longint;
	v,w:array[0..maxn]of longint;
	f:array[0..maxv*2,0..maxns+1]of longint;

function min(a,b:longint):longint; inline;
begin
	if a<b then exit(a) else exit(b);
end;

procedure insert(p,k:longint);
var
	i:longint;
begin
	if k>max then max:=k;
	for i:=f[p,0] downto 0 do if i>0 then
		if k>f[p,i] then
			f[p,i+1]:=f[p,i]
		else break;
	if i>0 then f[p,i+1]:=k else f[p,1]:=k;
	if f[p,0]<ns then inc(f[p,0]);
end;

begin



	readln(ns,vv,n);
	for i:=1 to n do readln(v[i],w[i]);
        f[0,0]:=1;
	for k:=1 to n do
		for i:=vv downto 0 do if f[i,0]<>0 then
			for j:=1 to f[i,0] do
				insert(i+v[k],f[i,j]+w[k]);

	for i:=1 to f[vv,0] do inc(ans,f[vv,i]);
	writeln(ans);



end.
