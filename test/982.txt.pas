program P1493;
var
  i,j,k,l:longint;
  m,n:longint;
  x1,y1,x2,y2:longint;
  a:array [1..50,1..50] of longint;
  dp:array [1..100,1..100,1..100] of longint;
  check:array [1..100,1..100,1..100] of boolean;
begin
  fillchar(dp,sizeof(dp),0);fillchar(check,sizeof(check),false);
  {assi-gn(input,'p1493.in');assi-gn(output,'p1493.out');
  res-et(input);rew-rite(output);}
  readln(m,n);
  for i:=1 to m do
    for j:=1 to n do
      read(a[i,j]);
  //----------dp--------------
  dp[1,1,1]:=0; check[1,1,1]:=true;
  dp[2,1,2]:=a[2,1]+a[1,2]; check[2,1,2]:=true;
  dp[2,2,1]:=dp[2,1,2]; check[2,2,1]:=true;
  for i:=1 to n+m-1 do
    for j:=1 to i do
      for k:=1 to i do
        if (j<>k) and (check[i,j,k]) then
        begin
          if i<n then
          begin
            x1:=i-j+1;
            y1:=j;
            x2:=i-k+1;
            y2:=k;
            //-------------
            if (x1+1<=n) and (x2+1<=n) then
              if dp[i,j,k]+a[y1,x1+1]+a[y2,x2+1]>dp[i+1,j,k] then
              begin
                dp[i+1,j,k]:=dp[i,j,k]+a[y1,x1+1]+a[y2,x2+1];
                check[i+1,j,k]:=true
              end;

            if (x1+1<=n) and (y2+1<=m) then
              if dp[i,j,k]+a[y1,x1+1]+a[y2+1,x2]>dp[i+1,j,k+1] then
              begin
                dp[i+1,j,k+1]:=dp[i,j,k]+a[y1,x1+1]+a[y2+1,x2];
                check[i+1,j,k+1]:=true
              end;

            if (y1+1<=m) and (x2+1<=n) then
              if dp[i,j,k]+a[y1+1,x1]+a[y2,x2+1]>dp[i+1,j+1,k] then
              begin
                dp[i+1,j+1,k]:=dp[i,j,k]+a[y1+1,x1]+a[y2,x2+1];
                check[i+1,j+1,k]:=true
              end;

            if (y1+1<=n) and (y2+1<=m) then
              if dp[i,j,k]+a[y1+1,x1]+a[y2+1,x2]>dp[i+1,j+1,k+1] then
              begin
                dp[i+1,j+1,k+1]:=dp[i,j,k]+a[y1+1,x1]+a[y2+1,x2];
                check[i+1,j+1,k+1]:=true;
              end;
          end
          else begin
            x1:=n-j+1;
            y1:=i-n+j;
            x2:=n-k+1;
            y2:=i-n+k;
            //-------------------
            if (x1+1<=n) and (x2+1<=n) then
              if dp[i,j,k]+a[y1,x1+1]+a[y2,x2+1]>dp[i+1,j-1,k-1] then
              begin
                dp[i+1,j-1,k-1]:=dp[i,j,k]+a[y1,x1+1]+a[y2,x2+1];
                check[i+1,j-1,k-1]:=true
              end;

            if (x1+1<=n) and (y2+1<=m) then
              if dp[i,j,k]+a[y1,x1+1]+a[y2+1,x2]>dp[i+1,j-1,k] then
              begin
                dp[i+1,j-1,k]:=dp[i,j,k]+a[y1,x1+1]+a[y2+1,x2];
                check[i+1,j-1,k]:=true
              end;
              
            if (y1+1<=m) and (x2+1<=n) then
              if dp[i,j,k]+a[y1+1,x1]+a[y2,x2+1]>dp[i+1,j,k-1] then
              begin
                dp[i+1,j,k-1]:=dp[i,j,k]+a[y1+1,x1]+a[y2,x2+1];
                check[i+1,j,k-1]:=true
              end;
              
            if (y1+1<=n) and (y2+1<=m) then
              if dp[i,j,k]+a[y1+1,x1]+a[y2+1,x2]>dp[i+1,j,k] then
              begin
                dp[i+1,j,k]:=dp[i,j,k]+a[y1+1,x1]+a[y2+1,x2];
                check[i+1,j,k]:=true
              end;
          end;
        end;
  if dp[n+m-2,1,2]>=dp[n+m-2,2,1] then
    writeln(dp[n+m-2,1,2])
  else
    writeln(dp[n+m-2,2,1]);
  {cl-ose(input);cl-ose(output);}
end.        
