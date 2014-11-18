{
ID:shadow_3
PROG:p1445
LANG:PASCAL
}

const
	maxn=200000;

var
	i,j,n,m:longint;
	a,b,xh,ans:array[0..maxn]of longint;

procedure swap(var a,b:longint);
var
	t:longint;
begin
	t:=a;
	a:=b;
	b:=t;
end;

procedure qsorta(f,r:longint);
var
	ff,rr,x:longint;
begin
	if f<r then
	begin
		ff:=f-1;
		rr:=r+1;
		x:=a[f];
		while ff<=rr do
		begin
			repeat inc(ff) until (ff>r) or (a[ff]<=x);
			repeat dec(rr) until (rr<f) or (a[rr]>=x);
			if ff<rr then swap(a[ff],a[rr]);
		end;
		qsorta(f,rr);
		qsorta(ff,r);
	end;
end;

procedure qsortb(f,r:longint);
var
	ff,rr,x:longint;
begin
	if f<r then
	begin
		ff:=f-1;
		rr:=r+1;
		x:=b[f];
		while ff<=rr do
		begin
			repeat inc(ff) until (ff>r) or (b[ff]<=x);
			repeat dec(rr) until (rr<f) or (b[rr]>=x);
			if ff<rr then
			begin
				swap(b[ff],b[rr]);
				swap(xh[ff],xh[rr]);
			end;
		end;
qsortb(f,rr);
qsortb(ff,r);
	end;
end;

begin

	readln(n,m);
	for i:=1 to n do read(a[i]);
	qsorta(1,n);
	for i:=1 to m do
	begin
		xh[i]:=i;
		read(b[i]);
	end;
	qsortb(1,n);
	for i:=1 to n do inc(ans[xh[(i-1) mod m+1]],a[i]);
	for i:=1 to m-1 do write(ans[i],' ');
	writeln(ans[m]);

end.
