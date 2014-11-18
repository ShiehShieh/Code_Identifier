{
ID:shadow_3
PROG:p1048
LANG:PASCAL
}

var
	i,n,j,t,min,a,b,sum:longint;
	w,went,xh,wz:array[0..100]of longint;
	g:array[0..100,0..100]of longint;

procedure dfs(dep,ans:longint);
var
	i:longint;
begin
	if ans>min then exit;
	if dep>n then
	begin
		min:=ans;
		exit;
	end;
	if went[dep]>0
		then dfs(dep+1,ans+w[dep])
		else begin
			inc(went[dep]);
			for i:=1 to g[dep,0] do inc(went[g[dep,i]]);
			dfs(dep+1,ans);
			for i:=1 to g[dep,0] do dec(went[g[dep,i]]);
			dec(went[dep]);
			dfs(dep+1,ans+w[dep]);
		end;
end;

begin


	readln(n);
	for i:=1 to n do
	begin
		read(w[i]);
                xh[i]:=i;
		inc(sum,w[i]);
	end;
	for i:=1 to n-1 do
		for j:=i+1 to n do if w[i]<w[j] then
		begin
			t:=w[i];
			w[i]:=w[j];
			w[j]:=t;
                        t:=xh[i];
                        xh[i]:=xh[j];
                        xh[j]:=t;
		end;
        for i:=1 to n do wz[xh[i]]:=i;
	readln;
	while not eof do
	begin
		readln(a,b);
                a:=wz[a];
                b:=wz[b];
		inc(g[a,0]);
		g[a,g[a,0]]:=b;
		inc(g[b,0]);
		g[b,g[b,0]]:=a;
	end;

	min:=maxlongint;
	dfs(1,0);
	writeln(sum-min);



end.

