{
ID:shadow_3
PROG:p1119
LANG:PASCAL
}

const
	maxn=100;

var
        n,a,b,i,j,f,r:longint;
	t,ti,min,x1,y1,x2,y2,x3,y3,x4,y4:extended;
	went:array[0..maxn*5]of boolean;
	dist,x,y:array[0..maxn*5]of extended;
        q:array[0..maxn*5*maxn*5]of longint;
	dis:array[0..maxn*5,0..maxn*5]of extended;

begin



	readln(n,t,a,b);
	for i:=1 to n do
	begin
		read(x1,y1,x2,y2,x3,y3);
		if sqr(x2-x1)+sqr(y2-y1)+sqr(x3-x1)+sqr(y3-y1)=sqr(x3-x2)+sqr(y3-y2) then
		begin
			x4:=x3+x2-x1;
			y4:=y3+y2-y1;
		end;
		if sqr(x1-x2)+sqr(y1-y2)+sqr(x3-x2)+sqr(y3-y2)=sqr(x3-x1)+sqr(y3-y1) then
		begin
			x4:=x1+x3-x2;
			y4:=y1+y3-y2;
		end;
		if sqr(x2-x3)+sqr(y2-y3)+sqr(x1-x3)+sqr(y1-y3)=sqr(x1-x2)+sqr(y1-y2) then
		begin
			x4:=x1+x2-x3;
			y4:=y1+y2-y3;
		end;
		readln(ti);
		x[i*4-3]:=x1;
		y[i*4-3]:=y1;
		x[i*4-2]:=x2;
		y[i*4-2]:=y2;
		x[i*4-1]:=x3;
		y[i*4-1]:=y3;
		x[i*4]:=x4;
		y[i*4]:=y4;
		dis[i*4-3,i*4-2]:=sqrt(sqr(x1-x2)+sqr(y1-y2))*ti;
		dis[i*4-2,i*4-3]:=dis[i*4-3,i*4-2];
		dis[i*4-3,i*4-1]:=sqrt(sqr(x3-x1)+sqr(y3-y1))*ti;
		dis[i*4-1,i*4-3]:=dis[i*4-3,i*4-1];
		dis[i*4-3,i*4]:=sqrt(sqr(x4-x1)+sqr(y4-y1))*ti;
		dis[i*4,i*4-3]:=dis[i*4-3,i*4];
		dis[i*4-1,i*4-2]:=sqrt(sqr(x3-x2)+sqr(y3-y2))*ti;
		dis[i*4-2,i*4-1]:=dis[i*4-1,i*4-2];
		dis[i*4,i*4-2]:=sqrt(sqr(x4-x2)+sqr(y4-y2))*ti;
		dis[i*4-2,i*4]:=dis[i*4,i*4-2];
		dis[i*4,i*4-1]:=sqrt(sqr(x4-x3)+sqr(y4-y3))*ti;
		dis[i*4-1,i*4]:=dis[i*4,i*4-1];
	end;

	for i:=1 to n*4 do
		for j:=1 to n*4 do if (i-1)div 4<>(j-1)div 4 then
			dis[i,j]:=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]))*t;

	min:=1e100;
	for i:=1 to 4 do
	begin
		fillchar(went,sizeof(went),0);
		f:=1;
		r:=1;
		for j:=1 to n*4 do dist[j]:=1e100;
		dist[(a-1)*4+i]:=0;
		q[f]:=(a-1)*4+i;
		while f<=r do
		begin
			went[q[f]]:=false;
			for j:=1 to n*4 do if dist[j]>dist[q[f]]+dis[q[f],j] then
			begin
				dist[j]:=dist[q[f]]+dis[q[f],j];
				if not went[j] then
				begin
					inc(r);
                                        q[r]:=j;
					went[j]:=true;
				end;
			end;
			inc(f);
		end;
		for j:=1 to 4 do if dist[(b-1)*4+j]<min
			then min:=dist[(b-1)*4+j];
	end;

	writeln(min:0:2);
	

end.

