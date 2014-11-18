Var lt,inq,dist,dista:array[1..1000] of longint;
    q,qq:array[-1000000..1000000] of longint;
    use:array[1..1000] of boolean;
    e:array[1..1000,1..2000] of record b,c:longint; end;
    l,r,p,i,a,b,c,n,m,s:longint;
Procedure printno;
 begin
  writeln(-1);
  halt;
 end;
Procedure spfa(s:longint);
 var i:longint;
 begin
 for i:=1 to n do dist[i]:=maxlongint;
 dist[s]:=0;
 l:=1;
 r:=1;
 q[1]:=s;
 while l<=r do
  begin
   p:=q[l];
   for i:=1 to lt[p] do
    if dist[p]+e[p,i].c<dist[e[p,i].b] then
     begin
      dist[e[p,i].b]:=dist[p]+e[p,i].c;
      if dist[e[p,i].b]<-1000000000 then printno;
      if not use[e[p,i].b] then
       begin
        use[e[p,i].b]:=true;
        inc(inq[e[p,i].b]);
        if inq[e[p,i].b]>n then printno;
        if (l<>r) and (dist[e[p,i].b]<dist[q[l+1]]) then begin q[l]:=e[p,i].b;dec(l); end
        else begin inc(r);q[r]:=e[p,i].b;end;
       end;
     end;
   use[p]:=false;
   inc(l);
  end;
 end;

Begin

 read(n,m,s);
 for i:=1 to m do
  begin
   read(a,b,c);
   inc(lt[a]);
   e[a,lt[a]].b:=b;
   e[a,lt[a]].c:=c;
  end;
 spfa(s);
 dista:=dist;
 for i:=1 to n do if dista[i]=maxlongint then spfa(i);
 for i:=1 to n do
  if dista[i]<maxlongint then writeln(dista[i]) else writeln('NoPath');

End.
