program p1323;
var i,j,k,l,n,ans:longint;
    s:string;
    sa,sb:array[1..100] of longint;
    dp:array[10..100,0..10,0..10] of longint;
function solve(x,y,z:longint):longint;
  var ans:longint;
  begin
    ans:=0;
    y:=y+sa[n]-sa[x];
    z:=z+sb[n]-sb[x];
    if y>0 then inc(ans);
    if z>0 then inc(ans);
    if y+z<10 then inc(ans);
    solve:=ans;
  end;
begin
  readln(n);
  sa[0]:=0;sb[0]:=0;
  for i:=1 to n do
    begin
      readln(s);
      sa[i]:=sa[i-1];
      sb[i]:=sb[i-1];
      if s='A' then inc(sa[i]);
      if s='B' then inc(sb[i]);
    end;
  if n<10 then
     begin
       ans:=0;
       i:=sa[n];j:=sb[n];
       if i>0 then inc(ans);
       if j>0 then inc(ans);
       if i+j<n then inc(ans);
       writeln(ans);exit;
     end;
  for i:=10 to n do
    for j:=0 to 10 do
      for k:=0 to 10-j do
        dp[i][j][k]:=maxlongint;
  dp[10][sa[10]][sb[10]]:=0;
  for i:=10 to n-1 do
    for j:=0 to 10 do
      for k:=0 to 10-j do
        begin
          l:=10-j-k;
          if dp[i][j][k]=maxlongint then continue;
          if (i+j<n) and (dp[i][j][k]+1<dp[i+j][sa[i+j]-sa[i]][k+sb[i+j]-sb[i]]) then
             dp[i+j][sa[i+j]-sa[i]][k+sb[i+j]-sb[i]]:=dp[i][j][k]+1;
          if i+j>=n then
             begin
               ans:=dp[i][j][k]+1;
               ans:=ans+solve(i,0,k);
               if ans<dp[n][0][0] then dp[n][0][0]:=ans;
             end;
          if (i+k<n) and (dp[i][j][k]+1<dp[i+k][j+sa[i+k]-sa[i]][sb[i+k]-sb[i]]) then
             dp[i+k][j+sa[i+k]-sa[i]][sb[i+k]-sb[i]]:=dp[i][j][k]+1;
          if i+k>=n then
             begin
               ans:=dp[i][j][k]+1;
               ans:=ans+solve(i,j,0);
               if ans<dp[n][0][0] then dp[n][0][0]:=ans;
             end;
          if (i+l<n) and (dp[i][j][k]+1<dp[i+l][j+sa[i+l]-sa[i]][k+sb[i+l]-sb[i]]) then
             dp[i+l][j+sa[i+l]-sa[i]][k+sb[i+l]-sb[i]]:=dp[i][j][k]+1;
          if i+l>=n then
             begin
               ans:=dp[i][j][k]+1;
               ans:=ans+solve(i,j,k);
               if ans<dp[n][0][0] then dp[n][0][0]:=ans;
             end;
        end;
  writeln(dp[n][0][0]);
end.

