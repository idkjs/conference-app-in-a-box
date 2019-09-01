// open ReactNative;
YellowBox.ignoreWarnings([|
  "Possible Unhandled Promise Rejection",
  "Remote debugger",
  "UIManager['getConstants']"
|]);

Amplify.configure;

let default = () => <Main />;
