{
ID:shadow_3
PROG:p1518
LANG:PASCAL
}

type
	ttype=record
		lc,rc,x:longint;
                w:int64;
	end;

var
	i,j,k,kk,n,rp,tree:longint;
	dis:array[0..200,0..200]of longint;
        g:array[0..200,0..200]of boolean;
        fr:array[0..200,0..200,0..200]of int64;
	w,p,d:array[0..200]of int64;
	t:array[0..200]of ttype;

function dfs(x:longint):longint;
var
	tmp,temp,tt,i:longint;
begin
	inc(rp);
	tmp:=rp;
	t[tmp].w:=w[x];
	t[tmp].x:=x;
	dfs:=tmp;
temp:=0;
	for i:=1 to n do if g[x,i] then
	begin
		t[tmp].lc:=dfs(i);
		tt:=t[tmp].lc;
		temp:=i;
		break;
	end;
	for i:=temp+1 to n do if g[x,i] then
	begin
		t[tt].rc:=dfs(i);
		tt:=t[tt].rc;
	end;
end;

function f(i,j,k:longint):int64;
var
	l:longint;
        s1:int64;
begin
        //if i=0 then exit(0);
        if fr[i,j,k]<>-1 then exit(fr[i,j,k]);
	if (t[i].lc=0) and (t[i].rc=0) then
		if k<>0 then
                begin
                        fr[i,j,k]:=0;
                        exit(0)
                end
                else begin
                        fr[i,j,k]:=t[i].w*dis[t[i].x,t[j].x];
                        exit(fr[i,j,k]);
                end;

	s1:=maxlongint*100000;
	for l:=0 to k do if f(t[i].lc,j,l)+f(t[i].rc,j,k-l)+dis[t[i].x,t[j].x]*t[i].w<s1
		then s1:=f(t[i].lc,j,l)+f(t[i].rc,j,k-l)+dis[t[i].x,t[j].x]*t[i].w;
	for l:=0 to k-1 do if f(t[i].lc,i,l)+f(t[i].rc,j,k-l-1)<s1
		then s1:=f(t[i].lc,i,l)+f(t[i].rc,j,k-l-1);
	fr[i,j,k]:=s1;
	f:=s1;
end;

begin



	readln(n,k);
	for i:=0 to n do
		for j:=0 to n do dis[i,j]:=maxint;
	for i:=1 to n do
	begin
		readln(w[i],p[i],d[i]);
		g[p[i],i]:=true;
		dis[p[i],i]:=d[i];
		dis[i,p[i]]:=d[i];
	end;
	for kk:=0 to n do
		for i:=0 to n do
			for j:=0 to n do if dis[i,kk]+dis[kk,j]<dis[i,j]
				then dis[i,j]:=dis[i,kk]+dis[kk,j];

	tree:=dfs(0);
        for i:=0 to n+1 do
                for j:=0 to n+1 do
                        for kk:=0 to n do fr[i,j,kk]:=-1;
	writeln(f(tree,tree,k));
        {for i:=0 to n+1 do
                for j:=0 to n+1 do
                        for kk:=0 to n do if fr[i,j,kk]<>-1 then
                                writeln(i,' ',j,' ',t[i].x,' ',t[j].x,' ',kk,' ',fr[i,j,kk]);}


end.
