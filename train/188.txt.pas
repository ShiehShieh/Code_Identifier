const www=-12345678;
type point=^node;
     node=record
     num,sum,high,value:longint;left,right,fa:point;end;
var qu:array[1..50000,1..4]of longint;
    b,c,e,f,g,h,i,j,k,m,n:longint;
    a:array[1..100000]of longint;
    ans:array[1..50000]of longint;
    d:array[0..100000]of point;
function max(a1,a2:longint):longint;
begin if a1>a2 then max:=a1 else max:=a2;end;
function min(a1,a2:longint):longint;
begin if a1<a2 then min:=a1 else min:=a2;end;
procedure qsort(i2,j2:longint);
var i1,j1,p,x1,x2,x3,x4:longint;
begin
    if i2>=j2 then exit;
    i1:=i2;j1:=j2;p:=random(j2-i2+1)+i2;
    x1:=qu[p,1];qu[p,1]:=qu[i1,1];x2:=qu[p,2];qu[p,2]:=qu[i1,2];
    x3:=qu[p,3];qu[p,3]:=qu[i1,3];x4:=qu[p,4];qu[p,4]:=qu[i1,4];
    while i1<j1 do
     begin
      while (i1<j1)and(qu[j1,1]>x1) do dec(j1);
      if i1<j1 then begin qu[i1,1]:=qu[j1,1];
         qu[i1,2]:=qu[j1,2];qu[i1,3]:=qu[j1,3];qu[i1,4]:=qu[j1,4];inc(i1);end;
      while (i1<j1)and(qu[i1,1]<x1) do inc(i1);
      if i1<j1 then begin qu[j1,1]:=qu[i1,1];
         qu[j1,2]:=qu[i1,2];qu[j1,3]:=qu[i1,3];qu[j1,4]:=qu[i1,4];dec(j1);end;
     end;
    qu[i1,1]:=x1;qu[i1,2]:=x2;qu[i1,3]:=x3;qu[i1,4]:=x4;
    qsort(i2,i1-1);qsort(i1+1,j2);
end;
procedure count(u:longint);
begin
    if (d[u]^.left=nil)and(d[u]^.right=nil) then
     begin d[u]^.sum:=1;d[u]^.high:=1;end else
    if d[u]^.left=nil then
     begin d[u]^.sum:=d[u]^.right^.sum+1;
           d[u]^.high:=d[u]^.right^.high+1;end else
    if d[u]^.right=nil then
     begin d[u]^.sum:=d[u]^.left^.sum+1;
           d[u]^.high:=d[u]^.left^.high+1;end else
     begin
      d[u]^.sum:=d[u]^.left^.sum+d[u]^.right^.sum+1;
      d[u]^.high:=max(d[u]^.left^.high,d[u]^.right^.high)+1;
     end;
end;
procedure tleft(u:longint);
var v,o:longint;
begin
    v:=d[u]^.right^.num;
    if (d[u]^.fa^.left<>nil)and(u=d[u]^.fa^.left^.num) then d[u]^.fa^.left:=d[v] else
     d[u]^.fa^.right:=d[v];
    d[v]^.fa:=d[u]^.fa;
    if d[v]^.left<>nil then
     begin
      o:=d[v]^.left^.num;
      d[u]^.right:=d[o];
      d[o]^.fa:=d[u];
     end else d[u]^.right:=nil;
    d[v]^.left:=d[u];d[u]^.fa:=d[v];
    count(u);count(v);
end;
procedure tright(u:longint);
var v,o:longint;
begin
    v:=d[u]^.left^.num;
    if (d[u]^.fa^.left<>nil)and(u=d[u]^.fa^.left^.num)
     then d[u]^.fa^.left:=d[v] else
     d[u]^.fa^.right:=d[v];
    d[v]^.fa:=d[u]^.fa;
    if d[v]^.right<>nil then
     begin
      o:=d[v]^.right^.num;
      d[u]^.left:=d[o];
      d[o]^.fa:=d[u];
     end else d[u]^.left:=nil;
    d[v]^.right:=d[u];d[u]^.fa:=d[v];
    count(u);count(v);
end;
procedure up(u:longint);
var lh,rh,o:longint;
begin
    if u=0 then exit;
    count(u);o:=d[u]^.fa^.num;
    if d[u]^.left=nil then lh:=0 else lh:=d[u]^.left^.high;
    if d[u]^.right=nil then rh:=0 else rh:=d[u]^.right^.high;
    if (d[u]^.fa^.left<>nil)and(u=d[u]^.fa^.left^.num) then
     begin
      if lh<rh then tleft(u);
     end else
     begin
      if lh>rh then tright(u);
     end;
    up(o);
end;
procedure insert(u,ii:longint);
begin
    if u=0 then
     begin
      if d[u]^.left=nil then
       begin d[u]^.left:=d[ii];d[ii]^.fa:=d[u];exit;end
      else insert(d[u]^.left^.num,ii);
     end else
    if d[ii]^.value>=d[u]^.value then
     begin
      if d[u]^.right=nil then
       begin
        d[u]^.right:=d[ii];d[ii]^.fa:=d[u];
        e:=u;
       end else
      insert(d[u]^.right^.num,ii);
     end else
     begin
      if d[u]^.left=nil then
       begin
        d[u]^.left:=d[ii];d[ii]^.fa:=d[u];
        e:=u;
       end else
      insert(d[u]^.left^.num,ii);
     end;
end;
function zhao(u:longint):longint;
begin
    if d[u]^.left=nil then exit(u) else
     zhao:=zhao(d[u]^.left^.num);
end;
procedure delete(u:longint);
var o,v,z:longint;
begin
    if d[u]^.right=nil then
     begin
      if d[u]^.left<>nil then d[u]^.left^.fa:=d[u]^.fa;
      if (d[u]^.fa^.left<>nil)and(d[u]^.fa^.left^.num=u) then
       begin
        d[u]^.fa^.left:=d[u]^.left;
       end else
       begin
        d[u]^.fa^.right:=d[u]^.left;
       end;
      if d[u]^.left<>nil then up(d[u]^.left^.num) else
       up(d[u]^.fa^.num);
     end else
     begin
      if d[u]^.right^.left=nil then
       begin
        o:=d[u]^.right^.num;
        if (d[u]^.fa^.left<>nil)and(d[u]^.fa^.left^.num=u) then
         begin
          d[u]^.fa^.left:=d[o];
          d[o]^.fa:=d[u]^.fa;
          d[o]^.left:=d[u]^.left;
          if d[u]^.left<>nil then d[u]^.left^.fa:=d[o];
         end else
         begin
          d[u]^.fa^.right:=d[o];
          d[o]^.fa:=d[u]^.fa;
          d[o]^.left:=d[u]^.left;
          if d[u]^.left<>nil then d[u]^.left^.fa:=d[o];
         end;
        up(o);
       end else
       begin
        o:=zhao(d[u]^.right^.num);
        d[o]^.fa^.left:=d[o]^.right;
        if d[o]^.right<>nil then d[o]^.right^.fa:=d[o]^.fa;
        z:=d[o]^.fa^.num;
        d[o]^.fa:=d[u]^.fa;
        d[o]^.left:=d[u]^.left;
        if d[u]^.left<>nil then d[u]^.left^.fa:=d[o];
        d[o]^.right:=d[u]^.right;d[u]^.right^.fa:=d[o];
        if (d[u]^.fa^.left<>nil)and(d[u]^.fa^.left^.num=u)
         then d[u]^.fa^.left:=d[o] else d[u]^.fa^.right:=d[o];
        up(z);
       end;
     end;
    d[u]^.fa:=nil;d[u]^.left:=nil;d[u]^.right:=nil;
end;
function dfs(u:longint):longint;
begin
    if u=d[0]^.left^.num then exit(0);
    if (d[u]^.fa^.right<>nil)and(d[u]^.fa^.right^.num=u) then
     dfs:=dfs(d[u]^.fa^.num)+d[u]^.fa^.sum-d[u]^.sum else
     dfs:=dfs(d[u]^.fa^.num);
end;
procedure search(u,w:longint);
var o:longint;
begin
    if d[u]^.left<>nil then o:=d[u]^.left^.sum+1 else o:=1;
     o:=o+dfs(u);
    if o=w then ans[qu[i,4]]:=a[u] else
    if o>w then search(d[u]^.left^.num,w) else
    search(d[u]^.right^.num,w);
end;
procedure did(u:longint);
begin
    if d[u]^.fa=nil then write('     ') else
    write('fa:',d[u]^.fa^.num,' ');
    if d[u]^.left<>nil then write('left :',d[u]^.left^.num,' ') else
     write('        ');
    if d[u]^.right<>nil then write('right:',d[u]^.right^.num,' ') else
     write('        ');
    writeln('num:',d[u]^.num,' value:',d[u]^.value,' sum:',d[u]^.sum,
            ' high:',d[u]^.high);
end;
begin
readln(n,m);randomize;
    for i:=1 to n do read(a[i]);readln;
    for i:=1 to m do
     begin readln(qu[i,1],qu[i,2],qu[i,3]);qu[i,4]:=i;
           e:=max(qu[i,1],qu[i,2]);qu[i,1]:=qu[i,1]+qu[i,2]-e;
           qu[i,2]:=e;end;
    qsort(1,m);
     for i:=0 to n do begin new(d[i]);d[i]^.left:=nil;d[i]^.value:=a[i];
        d[i]^.high:=1;d[i]^.right:=nil;d[i]^.fa:=nil;d[i]^.num:=i;end;
    b:=qu[1,1];c:=qu[1,2];
    for i:=b to c do
     begin
      e:=0;d[i]^.value:=a[i];d[i]^.sum:=1;insert(0,i);
      up(e);
     end;
    k:=qu[1,3];i:=1;
    search(d[0]^.left^.num,k);
    for i:=2 to m do
     begin
      for j:=b to min(qu[i,1]-1,qu[i-1,2]) do
       delete(j);
      for j:=max(c+1,qu[i,1]) to qu[i,2] do
       begin
        e:=0;d[j]^.value:=a[j];d[j]^.sum:=1;insert(0,j);
        up(e);
       // for h:=0 to n do did(h);
       end;
      k:=qu[i,3];
      search(d[0]^.left^.num,k);
      b:=qu[i,1];c:=max(qu[i,2],c);
     end;
    for i:=1 to m do write(ans[i]);
end.








