program vijos1382_kmp_minimum_representation;
type nexttype=array[1..1000100]of longint;
var s,t,u,w:ansistring;
    ans,p1,p2,i,j,k,n,lent,lens:longint;
    ch:char;
    next:nexttype;

begin
      
       readln(s);
       readln(t); lent:=length(t); lens:=length(s); u:=s+s; w:=t+t;
       if lent<>lens then begin writeln('No');halt; end;
       {get_next}
       i:=1; j:=0; next[1]:=0;
       while i<lent do
        if (j=0) or (t[i]=t[j])
         then begin
          inc(i); inc(j);
          k:=j;
          while (k>0) and (t[k]=t[i]) do k:=next[k];
          next[i]:=k;
         end
         else j:=next[j];
       {kmp}
       i:=1; j:=1;
       while (i<=2*lens) and (j<=lent) do
        if (j=0) or (u[i]=t[j])
         then begin
          inc(i); inc(j);
         end
         else j:=next[j];
       if j<=lent // j=lent+1 means to compare t[lent+1],so,1..lent are matched
        then writeln('No')
        else begin
         writeln('Yes');
         p1:=1; p2:=2; k:=0;
         while (p1<=lent) and (p2<=lent) and (k<=lent) do begin
          if u[p1+k]=u[p2+k]
           then inc(k)
           else begin
            if u[p1+k]>u[p2+k]
             then begin inc(p1,k+1); if p1<=p2 then p1:=p2+1; end
             else begin inc(p2,k+1); if p2<=p1 then p2:=p1+1; end;
            k:=0;
           end;
         end;
         if k>lent
          then begin
           if p1>p2 then ans:=p2 else ans:=p1;
          end
          else begin
           if p1>lent then ans:=p2 else ans:=p1;
          end;
         for i:=ans to lent do write(s[i]); for i:=1 to ans-1 do write(s[i]); writeln;
        end;

 end.
