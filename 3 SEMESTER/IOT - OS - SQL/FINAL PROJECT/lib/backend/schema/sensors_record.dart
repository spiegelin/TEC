import 'dart:async';

import 'package:collection/collection.dart';

import '/backend/schema/util/firestore_util.dart';
import '/backend/schema/util/schema_util.dart';

import 'index.dart';
import '/flutter_flow/flutter_flow_util.dart';

class SensorsRecord extends FirestoreRecord {
  SensorsRecord._(
    DocumentReference reference,
    Map<String, dynamic> data,
  ) : super(reference, data) {
    _initializeFields();
  }

  // "foco" field.
  bool? _foco;
  bool get foco => _foco ?? false;
  bool hasFoco() => _foco != null;

  // "temperature" field.
  String? _temperature;
  String get temperature => _temperature ?? '';
  bool hasTemperature() => _temperature != null;

  // "humidity" field.
  double? _humidity;
  double get humidity => _humidity ?? 0.0;
  bool hasHumidity() => _humidity != null;

  void _initializeFields() {
    _foco = snapshotData['foco'] as bool?;
    _temperature = snapshotData['temperature'] as String?;
    _humidity = castToType<double>(snapshotData['humidity']);
  }

  static CollectionReference get collection =>
      FirebaseFirestore.instance.collection('sensors');

  static Stream<SensorsRecord> getDocument(DocumentReference ref) =>
      ref.snapshots().map((s) => SensorsRecord.fromSnapshot(s));

  static Future<SensorsRecord> getDocumentOnce(DocumentReference ref) =>
      ref.get().then((s) => SensorsRecord.fromSnapshot(s));

  static SensorsRecord fromSnapshot(DocumentSnapshot snapshot) =>
      SensorsRecord._(
        snapshot.reference,
        mapFromFirestore(snapshot.data() as Map<String, dynamic>),
      );

  static SensorsRecord getDocumentFromData(
    Map<String, dynamic> data,
    DocumentReference reference,
  ) =>
      SensorsRecord._(reference, mapFromFirestore(data));

  @override
  String toString() =>
      'SensorsRecord(reference: ${reference.path}, data: $snapshotData)';

  @override
  int get hashCode => reference.path.hashCode;

  @override
  bool operator ==(other) =>
      other is SensorsRecord &&
      reference.path.hashCode == other.reference.path.hashCode;
}

Map<String, dynamic> createSensorsRecordData({
  bool? foco,
  String? temperature,
  double? humidity,
}) {
  final firestoreData = mapToFirestore(
    <String, dynamic>{
      'foco': foco,
      'temperature': temperature,
      'humidity': humidity,
    }.withoutNulls,
  );

  return firestoreData;
}

class SensorsRecordDocumentEquality implements Equality<SensorsRecord> {
  const SensorsRecordDocumentEquality();

  @override
  bool equals(SensorsRecord? e1, SensorsRecord? e2) {
    return e1?.foco == e2?.foco &&
        e1?.temperature == e2?.temperature &&
        e1?.humidity == e2?.humidity;
  }

  @override
  int hash(SensorsRecord? e) =>
      const ListEquality().hash([e?.foco, e?.temperature, e?.humidity]);

  @override
  bool isValidKey(Object? o) => o is SensorsRecord;
}
