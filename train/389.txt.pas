Var tl,tr,td:array[1..1000000] of longint;
    i,n,m:longint;
    x,y:longint;
Procedure create(k,l,r:longint);
 var m:longint;
 begin

  tl[k]:=l;tr[k]:=r;td[k]:=-maxlongint;
  if l=r then exit;
   m:=(l+r) shr 1;
  create(k*2,l,m);
  create(k*2+1,m+1,r);
 end;
Procedure insert(k,p:longint;data:longint);
  begin
   if tl[k]=0 then exit;
   if (p<tl[k]) or (p>tr[k]) then exit;
   if (tl[k]<=p) and (p<=tr[k]) and (data>td[k]) then td[k]:=data;
   if tl[k]<>tr[k]
    then
     begin
      if (tl[k]+tr[k]) shr 1>=p then insert(k*2,p,data)
                                else insert(k*2+1,p,data);
     end;
  end;
Function max(a,b:longint):longint;
 begin
  if a>b then max:=a else max:=b;
 end;
Function get(k,l,r:longint):longint;
 begin
  get:=-maxlongint;
  if l>tr[k] then exit;
  if r<tl[k] then exit;
  if (l<=tl[k]) and (r>=tr[k]) then get:=max(get,td[k])
   else
    begin
     get:=max(get(k*2,l,r),get(k*2+1,l,r));
    end;
 end;
Begin

 readln(n);
 create(1,1,n);
 for i:=1 to n do
  begin
   read(x);
   insert(1,i,x);
  end;
 read(m);
 for i:=1 to m do
  begin
   read(x,y);

   writeln(get(1,x,y));
  end;

End.
