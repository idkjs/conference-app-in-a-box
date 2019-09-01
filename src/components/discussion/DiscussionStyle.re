open ReactNative;
include Theme;
let styles =
  StyleSheet.create(
    Style.{
      "buttonContainer": style(~flexDirection=`row, ()),
      "input":
        style(
          ~width=dimensions##width->dp,
          ~height=50.->dp,
          ~backgroundColor="#fff",
          ~paddingHorizontal=8.->dp,
          ~fontFamily=Typography.primary,
          ~fontSize=16.,
          (),
        ),
      "container": style(~flex=1., ~backgroundColor=Colors.primary, ()),
      "scrollViewContainer": style(~flex=1., ~paddingBottom=50.->dp, ()),
      "time": style(~color="rgba(0, 0, 0, .5)", ()),
      "message":
        style(
          ~fontFamily=Typography.primary,
          ~color=Colors.primaryText,
          ~fontSize=16.,
          (),
        ),
      "createdBy":
        style(
          ~fontFamily=Typography.primary,
          ~color=Colors.highlight,
          ~marginTop=4.->dp,
          (),
        ),
      "comment":
        style(
          ~paddingHorizontal=10.->dp,
          ~paddingVertical=15.->dp,
          ~borderRadius=5.,
          ~backgroundColor=Colors.primaryDark,
          ~borderBottomColor="#25223e",
          ~borderBottomWidth=1.,
          (),
        ),
    },
  );