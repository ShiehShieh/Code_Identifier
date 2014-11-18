Var
	n,i,j,k,mk:longint;
	min,kk:real;
	f:array[1..1000,1..1000]of real;
	point:array[1..1000,1..2]of real;
Procedure Sort;
var
	i,j,k:integer;
	tem:real;
begin
	for i:=1 to n-1 do
	  begin
	  k:=i;
	  for j:=i+1 to n do
	    if point[k,1]>point[j,1] then k:=j;
	  if k<>i then
	    begin
	    tem:=point[k,1];point[k,1]:=point[i,1];point[i,1]:=tem;
	    tem:=point[k,2];point[k,2]:=point[i,2];point[i,2]:=tem;
	    end;
	  end;
end;
Function Dist(a,b:integer):real;
begin
	dist:=sqrt((point[a,1]-point[b,1])*(point[a,1]-point[b,1])+(point[a,2]-point[b,2])*(point[a,2]-point[b,2]));
end;
Begin
	readln(n);
	for i:=1 to n do
	  readln(point[i,1],point[i,2]);
	sort;
	fillchar(f,sizeof(f),0);
	for i:=2 to n do
	  f[1,i]:=f[1,i-1]+dist(i-1,i);
	for i:=2 to n do
	  begin
	  for j:=1 to i do
	    begin
	    if (i>j+1)or((i=2)and(j=1)) then
	      f[i,j]:=f[i-1,j]+dist(i-1,i);
	    if (i=j+1)and((i<>2)and(j<>1)) then
	      begin
	      min:=999999999999999999999999;mk:=0;
	      for k:=1 to i-2 do
                begin
                kk:=dist(k,i);
	        if f[j,k]+kk<min then begin mk:=k;min:=f[j,k]+kk;end;
                end;
	      f[i,j]:=min;
	      end;
	    if i=j then f[i,j]:=f[i,j-1]+dist(j-1,j);
	    end;
	  end;
	writeln(f[n,n]:0:2);
End.

