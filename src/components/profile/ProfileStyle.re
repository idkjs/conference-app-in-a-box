open ReactNative;
include Theme;
let styles =
  StyleSheet.create(
    Style.{
      "buttonContainer": style(~flexDirection=`row, ()),
      "button":
        style(
          ~width=110.->dp,
          ~borderWidth=1.,
          ~borderColor=Colors.highlight,
          ~height=35.->dp,
          ~justifyContent=`center,
          ~alignItems=`center,
          ~marginTop=15.->dp,
          ~marginLeft=(-1.)->dp,
          ~marginRight=15.->dp,
          (),
        ),
      "buttonText":
        style(
          ~color=Colors.primaryText,
          ~marginTop=3.->dp,
          ~fontFamily=Typography.primary,
          ~fontSize=13.,
          (),
        ),
      "input":
        style(
          ~height=45.->dp,
          ~width=(dimensions##width -. 30.)->dp,
          ~borderBottomWidth=2.,
          ~marginBottom=8.->dp,
          ~color="rgba(255, 255, 255, .5)",
          ~fontSize=18.,
          ~fontFamily=Typography.primary,
          ~borderBottomColor=Colors.highlight,
          (),
        ),
      "twitterHandle":
        style(
          ~color=Colors.primaryText,
          ~fontFamily=Typography.primary,
          ~fontSize=18.,
          ~marginLeft=15.->dp,
          (),
        ),
      "iconContainer":
        style(
          ~marginTop=5.->dp,
          ~flexDirection=`row,
          ~alignItems=`center,
          (),
        ),
      "gitHub": style(~marginTop=1.->dp, ()),
      "container": style(~flex=1., ~backgroundColor=Colors.primary2, ()),
      "profileContainer": style(~padding=20.->dp, ()),
      "username":
        style(
          ~fontSize=26.,
          ~marginBottom=3.->dp,
          ~color=Colors.primaryText,
          ~fontFamily=Typography.primary,
          (),
        ),
      "email":
        style(
          ~color=Colors.primaryText,
          ~fontSize=18.,
          ~marginBottom=10.->dp,
          ~fontFamily=Typography.primary,
          (),
        ),
    },
  );