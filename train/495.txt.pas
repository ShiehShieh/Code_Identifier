{
ID:shadow_3
PROG:p1118
LANG:PASCAL
}

const
	maxn=500;
	maxk=50;

var
	i,p,q,n,m,j,k,ii,jj,rp:longint;
	st,t:string;
        s:ansistring;
	x:array[0..maxk]of string;
	f,g:array[0..maxn*2,0..maxn*2]of longint;

function check(ss:string;st:longint):boolean;
var
	i:longint;
begin
	for i:=1 to length(ss) do
		if ss[i]<>s[st+i-1] then exit(false);
	exit(true);
end;

procedure max(var a:longint;b:longint); inline;
begin
	if b>a then a:=b;
end;

begin


	readln(p,q);
	for i:=1 to p do
	begin
		readln(st);
		s:=s+st;
	end;
	n:=length(s);
	for i:=1 to 100 do s:=s+'  ';
	readln(rp);
	for i:=1 to rp do readln(x[i]);
	for i:=1 to rp-1 do
		for j:=i+1 to rp do if length(x[i])>length(x[j]) then
		begin
			t:=x[i];
			x[i]:=x[j];
			x[j]:=t;
		end;

	for i:=1 to n do
		for k:=1 to rp do if check(x[k],i) then
		begin
			for ii:=1 to i do
				for jj:=i+length(x[k])-1 to n do inc(g[ii,jj]);
			break;
		end;
        for j:=0 to n do
                for i:=1 to q do f[j,i]:=-maxint;
	for i:=1 to q do
		for j:=0 to n do
			for k:=1 to n-j do
				max(f[j+k,i],f[j,i-1]+g[j+1,j+k]);
	writeln(f[n,q]);


end.
