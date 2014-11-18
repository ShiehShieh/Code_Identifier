
const maxn=1000;
var
   x,y:array[1..maxn] of real;
   f,dist:array[0..maxn,0..maxn] of real;
   i,j,n,k:longint;
   min:real;
procedure qsort(p,q:longint);
var
   i,j:longint;
   temp,mid:real;
begin
     i:=p;j:=q;mid:=x[(i+j) div 2];
     repeat
           while x[i]>mid do inc(i);
           while x[j]<mid do dec(j);
           if i<=j
              then
              begin
                   temp:=x[i];
                   x[i]:=x[j];
                   x[j]:=temp;
                   temp:=y[i];
                   y[i]:=y[j];
                   y[j]:=temp;
                   inc(i);dec(j);
              end;
     until i>j;
     if i<q then qsort(i,q);
     if j>p then qsort(p,j);
end;
function d(x1,x2,y1,y2:real):real;
begin
     d:=sqrt(sqr(x1-x2)+sqr(y1-y2));
end;
begin
     readln(n);
     for i:=1 to n do readln(x[i],y[i]);
     qsort(1,n);
     for i:=1 to n do
         for j:=1 to n do
             dist[i,j]:=d(x[i],x[j],y[i],y[j]);
     for i:=1 to n do
         for j:=1 to i-1 do
             if j=1
                then f[i,j]:=f[i-1,1]+dist[i-1,i]
                else if j=i-1
                        then
                        begin
                             min:=10000000000000;
                             for k:=1 to j-1 do
                                 if f[i-1,k]+dist[k,i]<min
                                    then min:=f[i-1,k]+dist[k,i];
                             f[i,j]:=min;
                        end
                else f[i,j]:=f[i-1,j]+dist[i-1,i];
     writeln(f[n,n-1]+dist[n-1,n]:0:2);
end.
