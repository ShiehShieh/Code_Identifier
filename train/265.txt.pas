var 
 t,l,i,j,k,n,wmax:longint; 
 a:array[1..1000,1..2]of longint; 
 f:array[1..1000]of integer; 
 lian:array[0..1000,0..1000]of longint; 
 flag:array[1..1000]of boolean; 
 p:array[0..1000,0..1000]of longint; 
 q:array[boolean,0..1000]of longint; 
 now:boolean; 
function max(x,y:longint):longint; 
 begin 
  if x>y then exit(x) 
         else exit(y); 
 end; 
procedure sam(step:longint); 
 var i,j:longint; 
 begin 
  for i:=1 to lian[step,0] do 
   if flag[lian[step,i]] then 
    begin 
     flag[lian[step,i]]:=false; 
     f[lian[step,i]]:=t; 
     sam(lian[step,i]); 
    end; 
 end; 
begin 
 readln(n,wmax,k); 
 for i:=1 to n do 
  readln(a[i,1],a[i,2]); 
 fillchar(lian,sizeof(lian),0); 
 fillchar(flag,sizeof(flag),false); 
 for i:=1 to k do 
  begin 
   readln(j,l); 
   flag[j]:=true;flag[l]:=true; 
   inc(lian[j,0]);lian[j,lian[j,0]]:=l; 
   inc(lian[l,0]);lian[l,lian[l,0]]:=j; 
  end; 
 t:=0; 
 fillchar(f,sizeof(f),0); 
 for i:=1 to n do 
  if flag[i]=true then 
  begin 
   inc(t);f[i]:=t; 
   flag[i]:=false; 
   sam(i); 
  end; 
 fillchar(lian,sizeof(lian),0); 
 for i:=1 to n do 
  begin 
   inc(lian[f[i],0]); 
   lian[f[i],lian[f[i],0]]:=i; 
  end; 
 fillchar(q,sizeof(q),0); 
 now:=true; 
 for i:=1 to lian[0,0] do 
  begin 
   for j:=1 to wmax do 
    begin 
     if j>=a[lian[0,i],2] then 
      q[not(now),j]:=max(q[now,j-a[lian[0,i],2]]+a[lian[0,i],1],q[now,j]) 
    else q[not(now),j]:=q[now,j]; 
    end; 
   now:=not(now); 
  end; 
 p[0]:=q[now]; 
 for i:=1 to t do 
  for j:=1 to lian[i,0] do 
   for k:=1 to wmax do 
    begin 
     if a[lian[i,j],2]<=k then 
      l:=max(p[i-1,k-a[lian[i,j],2]]+a[lian[i,j],1],p[i-1,k]) 
      else l:=p[i-1,k]; 
     p[i,k]:=max(p[i,k],l); 
    end; 
 writeln(p[t,wmax]); 
end. 

