{
ID:shadow_3
PROG:p1120
LANG:PASCAL
}

var
	i,j,n,m,x,y,tmpi,tmpj,max,time,ans:longint;
	g:array[0..50,0..50]of longint;

function min(a,b:longint):longint;
begin
        if a<b then exit(a) else exit(b);
end;

begin



	readln(n,m,time);
	max:=-1;
	for i:=1 to n do
		for j:=1 to m do
		begin
			read(g[i,j]);
			if g[i,j]>max then
			begin
				max:=g[i,j];
				tmpi:=i;
				tmpj:=j;
			end;
		end;

        g[tmpi,tmpj]:=-g[tmpi,tmpj];
	dec(time,tmpi+1);
	x:=tmpi;
	y:=tmpj;
	ans:=max;
	while true do
	begin
		if time<x then
		begin
			inc(ans,g[x,y]);
			break;
		end;
		max:=-1;
		for i:=1 to n do
			for j:=1 to m do if g[i,j]>max then
			begin
				max:=g[i,j];
				tmpi:=i;
				tmpj:=j;
			end;
		dec(time,min(abs(x-tmpi)+abs(y-tmpj),x+tmpi+maxint)+1);
		x:=tmpi;
		y:=tmpj;
		inc(ans,g[x,y]);
		g[x,y]:=-g[x,y];
	end;

	writeln(ans);

end.

