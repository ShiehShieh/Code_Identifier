{
ID:shadow_3
PROG:p1409
LANG:PASCAL
}

const
	maxn=100000;

var
	i,j,n,max,ans:longint;
	g:array[0..maxn]of longint;

procedure qsort(f,r:longint);
var
	ff,rr,x,t:longint;
begin
	if f<r then
	begin
		ff:=f-1;
		rr:=r+1;
		x:=g[f];
		while ff<=rr do
		begin
			repeat inc(ff) until (ff>r) or (g[ff]>=x);
			repeat dec(rr) until (rr<f) or (g[rr]<=x);
			if ff<rr then
			begin
				t:=g[ff];
				g[ff]:=g[rr];
				g[rr]:=t;
			end;
		end;
		qsort(f,rr);
		qsort(ff,r);
	end;
end;

begin



	readln(max);
	readln(n);
	for i:=1 to n do readln(g[i]);
	qsort(1,n);

	j:=1;
	for i:=n downto 1 do
	begin
		if i<j then break;
		inc(ans);
		if g[i]+g[j]<=max then inc(j);
	end;

	writeln(ans);


end.

