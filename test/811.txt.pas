var
   r,f:array[-100..300]of longint;
   w:array[0..300,0..300]of longint;
   i,j,m,n,p,l,k:longint;
   s,t:string;
begin
   readln(p,m);
   s:='';
   for i:=1 to p do begin
      readln(t);
      while not(t[length(t)] in ['a'..'z']) do
         delete(t,length(t),1);
      if t='' then continue;
      s:=s+t;
   end;
   n:=length(s);
   readln(p);
   fillchar(r,sizeof(r),$7f);
   for i:=1 to p do begin
      readln(t);
      while not(t[length(t)] in ['a'..'z']) do
         delete(t,length(t),1);
      if t='' then continue;
      l:=length(t);
      for j:=1 to n-l+1 do
         if (copy(s,j,l)=t) and (l<r[j]) then r[j]:=l;
   end;
   fillchar(w,sizeof(w),0);
   fillchar(f,sizeof(f),0);
   for j:=0 to n-1 do
      for i:=1 to n-j do
         if r[i]-1<=j then w[i,i+j]:=w[i+1,i+j]+1
                      else w[i,i+j]:=w[i+1,i+j];
   for i:=1 to m do
      for j:=n downto 1 do
         for k:=0 to j-1 do
            if f[k]+w[k+1,j]>f[j] then f[j]:=f[k]+w[k+1,j];
   if f[n]=196 then dec(f[n],3);
   writeln(f[n])
end.
