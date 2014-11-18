var
 f:array[1..20000]of integer;
 l1,l2:array[0..10001]of longint;
 i,j,t,n,p1,p2,ans:longint;
begin
 readln(n);
 fillchar(f,sizeof(f),0);
 for i:=1 to n do
  begin
   read(t);inc(f[t]);
  end;
 p1:=0;i:=1;
 while p1<>n do
  if f[i]=0 then inc(i) else
   begin
    dec(f[i]);
    inc(p1);l1[p1]:=i;
    dec(i);
   end;
 fillchar(l2,sizeof(l2),$7f);
 l1[n+1]:=maxlongint;p1:=1;p2:=1;ans:=0;
 for i:=1 to n-1 do
  begin
   t:=0;
   if l1[p1]<l2[p2] then begin inc(t,l1[p1]);inc(p1); end
                    else begin inc(t,l2[p2]);inc(p2); end;
   if l1[p1]<l2[p2] then begin inc(t,l1[p1]);inc(p1); end
                    else begin inc(t,l2[p2]);inc(p2); end;
   l2[i]:=t;inc(ans,t);
  end;
 writeln(ans)
end.

