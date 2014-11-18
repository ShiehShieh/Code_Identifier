const
	mxl=200000;
	ml=trunc(ln(mxl)/ln(2));
var
	st:array[0..mxl,0..ml]of int64;
	n,m,nl:longint;
	procedure init;
		var
			i:longint;
		begin
			read(n);
			for i:=1 to n do
				read(st[i,0]);
			nl:=trunc(ln(n)/ln(2));
		end;
	function max(const a,b:int64):int64;inline;
		begin
			if a>b then exit(A)else exit(b);
		end;
	procedure mkst;
		var
			i,j:longint;
		begin
			for j:=1 to nl do
				for i:=1 to (n-1 shl j+1) do
					st[i,j]:=max(st[i,j-1],st[i+1 shl (j-1),j-1]);
		end;
	procedure ans;
		var
			i,a,b,dt,c:longint;
		begin
			reaD(m);
			for i:=1 to m do
				begin
					readln(a,b);
					dt:=b-a;
					c:=trunc(ln(dt)/ln(2));
					write(max(st[a,c],st[b-1 shl c+1,c]));
				end;
		end;
	begin
			init;
			mkst;
			ans;
	end.
	

