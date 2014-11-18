{
ID:shadow_3
PROG:p1441
LANG:PASCAL
}
{$inline on}

const
	maxm=10000;

var
	i,n,m,j,tmpj,max:longint;
	xh,f,x,y,t:array[0..maxm]of longint;

function dis(a,b,c,d:longint):longint; inline;
begin
	exit(abs(a-c)+abs(d-b));
end;

begin


	readln(n,m);
	for i:=1 to m do readln(t[i],x[i],y[i]);
	for i:=1 to m do
	begin
		f[i]:=1;
		tmpj:=0;
		for j:=1 to i-1 do if dis(x[xh[j]],y[xh[j]],x[i],y[i])<=(t[i]-t[xh[j]]) then
		begin
			f[i]:=f[xh[j]]+1;
			tmpj:=j;
			break;
		end;
		if tmpj=0 then
		begin
                        xh[i]:=i;
			continue;
		end;
		j:=tmpj;
		repeat dec(j) until (j=0) or (f[xh[j]]>f[xh[tmpj]]);
		move(xh[j+1],xh[j+2],sizeof(longint)*(i-j+10));
		xh[j+1]:=i;
	end;
	for i:=1 to m do if f[i]>max then max:=f[i];

	writeln(max);


end.
