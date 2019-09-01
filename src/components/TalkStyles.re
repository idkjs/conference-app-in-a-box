open ReactNative;
include Theme;
let styles =
  StyleSheet.create(
    Style.{
      "avatar":
        style(
          ~width=(dimensions##width -. 40.)->dp,
          ~height=300.->dp,
          ~borderRadius=15.,
          (),
        ),
      "container":
        style(
          ~flex=1.,
          ~padding=30.->dp,
          ~backgroundColor=Colors.primaryLight,

          (),
        ),
      "title":
        style(
          ~fontSize=22.,
          ~marginTop=15.->dp,
          ~color=Colors.primaryText,
          ~fontFamily=Typography.medium,
          (),
        ),
      "name":
        style(
          ~fontSize=26.,
          ~marginBottom=20.->dp,
          ~marginTop=20.->dp,
          ~color=Colors.highlight,
          ~fontFamily=Typography.medium,
          (),
        ),
      "speakerName":
        style(
          ~marginBottom=5.->dp,
          ~fontSize=16.,
          ~color=Colors.primaryText,
          ~fontFamily=Typography.medium,
          (),
        ),

      "time":
        style(
          ~color=Colors.highlight,
          ~fontFamily=Typography.medium,
          (),
        ),

      "summary":
        style(
          ~marginTop=4.->dp,
          ~color=Colors.primaryText,
          ~fontFamily=Typography.primary,
          (),
        ),

      "speakerBio": style(~color=Colors.primaryText, ()),
    },
  );