program lx;
var a,g:array[1..100,1..100]of longint;min,n,m,i,j,x,y,z,k,p,q,u:longint;
    v:array[1..100]of boolean;b:array[1..100]of longint;
begin
 while not eof do
  begin
  readln(n,m);
  for i:=1 to n do
    for j:=1 to n do
      a[i,j]:=maxint;
  for i:=1 to m do
    begin
      readln(x,y,z);
      a[x,y]:=z;
      a[y,x]:=z;
    end;
  q:=maxint;
  for i:=1 to n do
    for j:=1 to n do
        if (a[i,j]<>maxint)and(q>a[i,j]) then
          begin
            g:=a;
            for k:=1 to n do v[k]:=true;
            v[i]:=false;g[i,j]:=maxint;g[j,i]:=maxint;
            u:=i;
            for k:=1 to n do b[k]:=maxint;
            b[u]:=0;
            for k:=1 to n-1 do
              begin
                for p:=1 to n do
                  if v[p] and (g[u,p]+b[u]<b[p])
                    then b[p]:=g[u,p]+b[u];
                min:=maxint;
                for p:=1 to n do
                  if v[p] and (b[p]<min) then
                    begin u:=p;min:=b[p];end;
                if u=j then break;
                v[u]:=false;
              end;
            if q>b[j]+a[i,j] then q:=b[j]+a[i,j];
        end;
      if q<>maxint then writeln(q) else writeln('No solution.');
  end;
end.

