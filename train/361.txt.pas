program vijos1118;
var s,s1:string;
    flag:boolean;
    p,m,i,j,k,ww,n,oo,len,size,t,max:longint;
    mas:array[0..10]of string;
    lm,num:array[0..10]of longint;
    sum,f,pt:array[0..201,0..201]of longint;
begin
     readln(p,m);
     readln(s);
     for i:=2 to p do
     begin
          readln(s1);
          s:=s+s1;
     end;
     readln(ww);
     size:=0;
     for i:=1 to ww do
     begin
          readln(mas[i]);
          lm[i]:=length(mas[i]);
          flag:=true;
          for j:=1 to size do
          if mas[i,1]=mas[pt[j,1],1]then
          begin
               flag:=false;
               inc(num[j]);
               pt[j,num[j]]:=i;
               break;
          end;
          if flag then
          begin
               inc(size);
               pt[size,1]:=i;
               num[size]:=1;
          end;
     end;
     n:=length(s);
     for len:=1 to n do
         for i:=1 to n-len+1 do
         begin
              j:=i+len-1;
              sum[i,j]:=0;
              for t:=1 to size do
                  for p:=i to j do
                  if s[p]=mas[pt[t,1],1]then
                  begin
                       max:=0;
                       for k:=1 to num[t] do
                       if (j>=p+lm[pt[t,k]]-1)then
                          if copy(s,p,lm[pt[t,k]])=mas[pt[t,k]]then
                          begin
                               max:=1;
                               break;
                          end;
                        inc(sum[i,j],max);
                  end;
         end;
         for j:=1 to n do f[1,j]:=sum[1,j];
         for i:=2 to m do
             for j:=1 to n do
                 for k:=i to j do
                 if f[i-1,k-1]+sum[k,j]>f[i,j] then
                 f[i,j]:=f[i-1,k-1]+sum[k,j];
         writeln(f[m,n]);
end.
