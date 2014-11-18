program Dzs;
var
q:array[0..160,0..8050]of longint;
x,y:array[1..160]of longint;
w,w1,r:array[0..160,0..160]of longint;
d,j1,a,n,i1,m,t,i,j,j2,k:longint;
function max(a,b:longint):longint;
begin
        if a>b then exit(a)
                else exit(b);
end;
begin
readln(n,m,t);
        for i:=1 to n do
        begin
        readln(x[i],y[i]);
        end;
        for i:=1 to n do
        begin
        i1:=i-1;
        for j:=i1 to n do
                for k:=0 to w[i1,j] do q[j,k]:=0;
        q[i,x[i]]:=y[i];w[i,i]:=x[i];
        if x[i]<=t then
                 w1[i,i]:=y[i];
            for j:=i+1 to n do
            begin
            j1:=j-1;j2:=(j-i+1)*t;
                for k:=0 to w[i,j1] do
                begin
                if q[j1,k]>q[j,k] then
                        begin
                                q[j,k]:=q[j1,k];
                                w[i,j]:=max(w[i,j],k);
                                if k<=j2 then w1[i,j]:=max(w1[i,j],q[j,k]);
                        end;
                if q[j,k+x[j]]<q[j1,k]+y[j] then
                        begin
                                d:=k+x[j];
                                q[j,d]:=q[j1,k]+y[j];
                                w[i,j]:=max(w[i,j],d);
                                if d<=j2 then
                                        w1[i,j]:=max(w1[i,j],q[j,d]);
                        end;
                end;
            end;
        end;
        for i:=1 to m do
                for j:=1 to n do
                        for k:=j-1 downto i-1 do
                        r[i,j]:=max(r[i,j],r[i-1,k]+w1[k+1,j]);
writeln(r[m,n]);
end.

 
