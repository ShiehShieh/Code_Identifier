{
ID:shadow_3
PROG:p1071
LANG:PASCAL
}

const
	maxw=200000;

var
	i,j,n,wt,rp:longint;
	w,fa,g,rec:array[0..maxw]of longint;
	jie:array[0..maxw]of int64;
        f,used:array[0..maxw]of boolean;

procedure special(x:longint);
begin
	writeln(x);
	halt;
end;

begin


	readln(wt);
	readln(n);
	for i:=1 to n do readln(w[i]);
	f[0]:=true;
	jie[0]:=1;
	for i:=1 to n do
		for j:=wt-w[i] downto 0 do if f[j] then
		begin
			f[j+w[i]]:=true;
			inc(jie[j+w[i]],jie[j]);
			if (g[j+w[i]]=0)
				then begin
					g[j+w[i]]:=i;
					fa[j+w[i]]:=j;
				end;
		end;

	if not f[wt] then special(0);
	if jie[wt]>1 then special(-1);
	used[g[wt]]:=true;
	j:=fa[wt];
	while j<>0 do
	begin
		used[g[j]]:=true;
		j:=fa[j];
	end;
	for i:=n downto 1 do if not used[i] then
	begin
		inc(rp);
		rec[rp]:=i;
	end;
	for i:=rp downto 1 do
		if i=1 then writeln(rec[i]) else write(rec[i],' ');


end.

