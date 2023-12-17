import 'package:firebase_core/firebase_core.dart';
import 'package:flutter/foundation.dart';

Future initFirebase() async {
  if (kIsWeb) {
    await Firebase.initializeApp(
        options: FirebaseOptions(
            apiKey: "AIzaSyCtCUfgugSpRJpBzwUUooWarogHGRfqR-s",
            authDomain: "appiot-c2fff.firebaseapp.com",
            projectId: "appiot-c2fff",
            storageBucket: "appiot-c2fff.appspot.com",
            messagingSenderId: "1042990183697",
            appId: "1:1042990183697:web:319ddbaa7b406c4ef808b0",
            measurementId: "G-K751XZZWFV"));
  } else {
    await Firebase.initializeApp();
  }
}
