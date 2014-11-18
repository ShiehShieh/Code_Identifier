{
ID:shadow_3
PROG:p1027
LANG:PASCAL
}

const
	maxn=200;
	maxm=500;

type
	btype=record
		e,c,next:longint;
	end;

var
	i,j,s,e,c,n,m,f,r,t,rp:longint;
	first,dist,rec:array[0..maxn+1]of longint;
	fa:array[0..maxn+1,0..maxn]of longint;
        went:array[0..maxn+1]of boolean;
        q:array[0..maxn*maxn]of longint;
	b:array[0..maxm+1]of btype;

begin



	readln(n);
	readln(m);
	for i:=1 to m do
	begin
		readln(s,e,c);
		inc(rp);
		b[rp].e:=e;
		b[rp].c:=-c;
		b[rp].next:=first[s];
		first[s]:=rp;
	end;

	q[1]:=1;
	f:=1;
	r:=1;
	for i:=2 to n+1 do dist[i]:=maxlongint;

	while f<=r do
	begin
		went[q[f]]:=false;
		t:=first[q[f]];
		while t<>0 do
		begin
			if dist[b[t].e]>dist[q[f]]+b[t].c then
			begin
				dist[b[t].e]:=dist[q[f]]+b[t].c;
                                fa[b[t].e,0]:=1;
				fa[b[t].e,1]:=q[f];
				if not went[b[t].e] then
				begin
					inc(r);
					q[r]:=b[t].e;
					went[b[t].e]:=true;
				end;
			end else if dist[b[t].e]=dist[q[f]]+b[t].c then
			begin
				inc(fa[b[t].e,0]);
				fa[b[t].e,fa[b[t].e,0]]:=q[f];
			end;
			t:=b[t].next;
		end;
		inc(f);
	end;

	writeln(-dist[n+1]);
	f:=1;
	r:=1;
	q[f]:=n+1;
	rp:=0;
	fillchar(went,sizeof(went),0);
	went[n+1]:=true;
	while f<=r do
	begin
		for i:=1 to fa[q[f],0] do if not went[fa[q[f],i]] then
		begin
			went[fa[q[f],i]]:=true;
			inc(r);
			q[r]:=fa[q[f],i];
		end;
		inc(f);
	end;
	for i:=n+1 downto 1 do if went[i] then
	begin
		inc(rp);
		rec[rp]:=i;
	end;
	for i:=rp downto 1 do if i=1
		then writeln(rec[i])
		else write(rec[i],' ');



end.

